#include <iostream>
#include <memory>
#include <functional>

struct MyStruct {
    int a;

    int operator()() {
        return a;
    }
};

// functional -> wrapper
// object? -> &shared_ptr -> int
// shared_ptr? -> destruct ref count = 0

int main() {
    std::function<int()> func;
    {
        auto a = std::make_shared<int>(10);

        auto lamb = [a]() mutable -> int {
            *a = *a + 1;
            return *a;
        };
        func = lamb;
    }

    MyStruct st{1};

    std::cout << st() << std::endl;
    std::cout << func() << std::endl;
    return 0;
}