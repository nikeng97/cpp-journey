#include <unistd.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <chrono>
#include <future>
#include <vector>

inline int64_t Now() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

int64_t Task(std::string name, int64_t time_s) {
  printf("%s is created, starting at time: %lld\n", name.c_str(), Now());
  sleep(time_s);
  printf("%s is done at time: %lld\n", name.c_str(), Now());
  return Now();
}

int main() {
  std::vector<std::future<int64_t>> t_list;
  for (int i = 0; i < 10; i++) {
    t_list.push_back(std::async(std::launch::async, Task, std::string("task ") + std::to_string(i + 1), i*2 + 1));
  }

  for (auto& task : t_list) {
    std::cout << task.get() << std::endl;
  }
  return 0;
}