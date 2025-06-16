#include <cxxabi.h>

#include <iostream>
#include <typeinfo>
#include <string>

// helper function to get type name
std::string demangle(const char* name) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(name, nullptr, nullptr, &status);
    std::string result = (status == 0) ? demangled : name;
    free(demangled);
    return result;
}

struct MyStruct {
    int att_1;
    float att_2;

    friend std::ostream& operator<<(std::ostream& os, const MyStruct& st) {
        os << "att_1: type: " << demangle(typeid(st.att_1).name()) << " value: " << st.att_1 << std::endl;
        os << "att_2: type: " << demangle(typeid(st.att_2).name()) << " value: " << st.att_2 << std::endl;
        return os;
    }
};

// auto type completion on variable initialization
auto var = 1u;

// auto type completion on function
auto DoSomething(auto var) {
    std::cout << "Describe: " << std::endl
              << "  type: " << demangle(typeid(var).name()) << std::endl
              << "  value: " << std::endl << var << std::endl;
    return var;
}

int main() {
    // Do something now works on variable type unsigned int
    DoSomething(var);
    // Do something now works on variable type MyStruct
    DoSomething(MyStruct{1, 1.0});

    /*
    These 2 function actually difference on each other,
    auto in function can be understood as functional template
    run: readelf -s --wide auto_type | grep DoSomething
    */

    /*
    So when should I use auto type and what is it trade off?
    - auto type help code more maintainable when you "unsure" about underlying type
    - interestingly, C/Cpp developer it's always to keep memory control and management mind set
    this broken completely when you try to use auto which limit understanding about it or metaprograming
    leading to hard to trace code and readability for new dev
    */
    return 0;
}