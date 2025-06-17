#include <vector>
#include <iostream>
#include <algorithm>

// stl container
// which to be used
// vector -> linear array: random access fast (indexing), lookup slow for huge data
//        -> insert/ delete costly
//           prepare slot -> insert/ delete slot -> arrange
//           memory pool (reserve size)
//        -> need iterate, small data, preinit
//        -> buffer for stream data
// list   -> linked list -> no random access, linear lookup
//        -> insert/ delete easy
//        -> need iterate, small data, dynamic
// map    -> binary tree no random access, log(n) lookup
// hash map / unordered map -> binary tree no random access, O(0) lookup worst O(n)
// set    -> ordered list -> can be random access (no duplication)
// multiset -> set -> can be duplication

// if i want to switch to another container -> how it can be change easily?
// best practice stl container
// 1. range base loop over index loop
// for (auto it : container) {
//  if (it == ) {
//        break;
//    }
//}
//}
// 2. using stl algorithm over iterate

template <typename T>
void Lookup(std::vector<T>& vt, const T& v) {
    auto it = std::find_if(vt.begin(), vt.end(), v);

    if (it != vt.end()) {
        std::cout << *it << std::endl;
    }
}

struct MyStruct {
    int a;
    int b;z

    bool operator==(const MyStruct& rhs) {
        return (this->a == rhs.a) && (this->b == rhs.b); // customize
    }

    bool operator()(const MyStruct& rhs) {
        return (this->a == rhs.a) && (this->b == rhs.b); // customize
    }

    friend std::ostream& operator<<(std::ostream& os, const MyStruct& st) {
        os << st.a << " " << st.b << std::endl;
        return os;
    }
};

int main() {
    std::vector<MyStruct> vt;
    MyStruct var{500, 501};
    // int var = 10;
    {
        for (int i = 0; i < 1000; i++) {
            vt.push_back(MyStruct{i, i+ 1});
        }
    }

    Lookup(vt, var);

    return 0;
}