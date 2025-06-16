#include <tuple>
#include <iostream>

// unnamed struct
struct MyStruct {
    float b;
    char a;
};

std::tuple<char, float> my_tuple;

int main() {
    std::cout << sizeof(MyStruct) << std::endl;
    std::cout << sizeof(my_tuple) << std::endl;
    return 0;
}