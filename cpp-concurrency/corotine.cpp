
#include <unistd.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <chrono>
#include <mutex>
#include <queue>
#include <memory>

inline int64_t Now() {
  return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

class Executor;

class TaskWrapper {
public:
  TaskWrapper(std::shared_ptr<Executor> exe) : exe_(exe) {}
  virtual void Resume() = 0;
protected:
  std::shared_ptr<Executor> exe_;
};

class Executor {
public:
  void Schedule(std::shared_ptr<TaskWrapper> task) {
    std::lock_guard<std::mutex> lk(mu);
    tasks.push(task);
  }
  void Run() {
    while(!tasks.empty()) {
      std::shared_ptr<TaskWrapper> task;
      {
        std::lock_guard<std::mutex> lk(mu);
        task = tasks.front();
        tasks.pop();
      }
      task->Resume();
    }
  }
private:
  std::queue<std::shared_ptr<TaskWrapper>> tasks;
  std::mutex mu;
};

class Task : public TaskWrapper , public std::enable_shared_from_this<Task> {
public:
  Task(std::string name, int64_t time_s, std::shared_ptr<Executor> exe)
  : TaskWrapper(exe), name_(name), time_s(time_s) {
    start_s = Now();
  }
  void Resume() override {
    printf("%s Resuming\n", name_.c_str());
    if (Now() - start_s < time_s) {
      printf("%s Suspend\n", name_.c_str());
      exe_->Schedule(shared_from_this());
    } else {
      printf("%s Done\n", name_.c_str());
      printf("============================== %s ==================================\n", name_.c_str());
    }
  }
private:
  std::string name_;
  int64_t time_s;
  int64_t start_s;
};

int main() {
  auto exe = std::make_shared<Executor>();
  for (int i = 0; i < 10; i++) {
    auto task = std::make_shared<Task>(std::string("task ") + std::to_string(i + 1), i*2 + 1, exe);
    exe->Schedule(task);
  }

  exe->Run();
  return 0;
}
/*
mixed of threading and coroutine
- multi executor -> thread
- Number of Task no change
- Scheduling mechanism (round robin, work stealing)
[ \ \ \] block
[ \ \ \ \] -> no task -> steal task from blocked executor
[ \ \ \ ]
RUST -> corotine + thread pool + work stealing (efficiently async)
*/