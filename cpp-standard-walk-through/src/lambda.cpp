#include <iostream>
#include <memory>
#include <functional>

struct MyStruct {
    // int a;
    // MyStruct(int a) : a(a) {}
    int operator()() {
        // return a;
        return 1;
    }
};

// functional -> wrapper
// object? -> &shared_ptr -> int
// shared_ptr? -> destruct ref count = 0

// functor?
// function pointer -> callable, no holding state
// object -> callable object

// class InterfaceA {
// public:
//     virtual void Foo() = 0;
// };

// class Impl : public InterfaceA {
// public:
//     void Foo() override;
// };

// void DoSmt(InterfaceA& inter) {
//     inter.Foo();
// }



// void DoSmt(std::function<void()> callable) {
//     callable();
// }

// // lazy design
// // Interface
// // 1 IO Get/Set
// void Foo(/*callable*/ std::function<int()>) {

// }

int main() {
    // std::function<int()> func;
    // {
    //     auto a = std::make_shared<int>(10);

    //     auto lamb = [a]() mutable -> int {
    //         *a = *a + 1;
    //         return *a;
    //     };
    //     func = lamb;
    // }

    // {
    //     auto lamb = []() {

    //     };
    //     DoSmt(lamb);
    // }

    MyStruct st{};

    std::cout << st() << std::endl;
    // std::cout << func() << std::endl;
    return 0;
}