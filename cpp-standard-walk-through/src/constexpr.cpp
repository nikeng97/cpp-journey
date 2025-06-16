#include <string.h>
#include <iostream>
#include <chrono>
#include <string>

void PrintDuration(auto duration) {
    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() << " ns" << std::endl;
}

constexpr int Evaluate(const char* str) {
    int i = 0;
    for (; str[i] != '\0'; i++) {

    }
    return i;
}

#define str "Hello, long stringggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg!"

int main(int argc, char** argv) {
    auto s = std::string(argv[1]);
    
    auto tic = std::chrono::steady_clock::now();
    std::cout << strlen(s.c_str()) << std::endl;
    auto toc = std::chrono::steady_clock::now();
    PrintDuration(toc - tic);
    tic = std::chrono::steady_clock::now();
    std::cout << Evaluate(s.c_str()) << std::endl;
    toc = std::chrono::steady_clock::now();
    PrintDuration(toc - tic);
    return 0;
}