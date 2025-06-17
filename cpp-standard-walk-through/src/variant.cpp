#include <variant>
#include <iostream>
#include <string>
#include <tuple>

std::variant<std::tuple<char, float>, int> x;

int main() {
    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(std::tuple<char, float>) << std::endl;
    return 0;
}