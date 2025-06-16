#include <vector>
#include <iostream>
#include <algorithm>

template <typename K, typename V>
using MyContainer = std::map<K,V>;

MyContainer<int, std::string> v;

template <typename K, typename V>
class MyContainer : public std::map<K, V> {
};

template <typename K, typename V>
class MyContainer {
public:
    void insert(K k, V v) {
        m_map.emplace(k, v);
    }

private:
    std::map<K, V> m_map;
};

template <typename T>
void Lookup(std::vector<T>& vt, const T& v) {
    auto it = std::find_if(vt.begin(), vt.end(), v);

    if (it != vt.end()) {
        std::cout << *it << std::endl;
    }
}

struct MyStruct {}
int main() {
    std::vector<MyStruct> vt;
    MyStruct var{500, 501};

    {
        for (int i = 0; i < 1000; i++) {
            vt.push_back(MyStruct{i, i+1});
        }
    }

    Lookup(vt, var);

    return 0;
}