#include <memory>
#include <iostream>

// what, why, how?
// unique, shared, weak
// 

struct B;
struct A {
    std::shared_ptr<B> b;
    int a;
    ~A() {
        std::cout << __func__ << std::endl;
        std::cout << b.use_count() << std::endl;
    }
};

struct B {
    std::shared_ptr<A> a;
    int b;
    ~B() {
        std::cout << __func__ << std::endl;
        std::cout << a.use_count() << std::endl;
    }
};

int main() {
    // std::unique_ptr<int> a = std::make_unique<int>(10);
    // std::unique_ptr<int> a = std::unique_ptr<int>(new int(10));
    // a.get(); // don't use

    // std::cout << "address: " << a.get() << std::endl;


// shared_ptr -> shared resource single resource passing around
// -> auto free after reference count = 0
// cross dependency
    std::shared_ptr<B> b;
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        a->b = std::make_shared<B>();
        a->b->a = a;
        b = a->b;
        std::cout << a.use_count() << " " << a->b.use_count() << std::endl;
    }
    std::cout << "hello\n";
    return 0;
}