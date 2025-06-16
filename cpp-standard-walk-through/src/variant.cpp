#include <variant>
#include <iostream>
#include <string>

struct MyStruct {
    float b;
    char a;
};

union MyUnion {
    char a;
    int b;
    double c;
    double d;
    MyStruct st;
};

std::variant<std::tuple<char, float>, int> x;


int main() {
    MyUnion u;
    // u.s = new std::string("Hello");
    std::cout << sizeof(MyUnion) << std::endl;
    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(std::tuple<char, float>) << std::endl;
    return 0;
}