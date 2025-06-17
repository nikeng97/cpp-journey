#include <iostream>
#include <string>

constexpr int Count(const char* str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

void func1() {
    // Precompile, i should be constant
    auto i = Count("Hello constexpr!");
}

void func2(const char* str) {
    // i now is not constant
    auto i = Count(str);
}

int main() {
    func1();
    func2("Hello");
    return 0;
}
