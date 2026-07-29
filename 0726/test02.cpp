#include <iostream>
#include <type_traits>

template<typename T>
void func(T a) {
    if constexpr (std::is_pointer<T>::value) {
        std::cout << "pointer" << "\n";
    } else {
        std::cout << "not pointer" << "\n";
    }
}

int main() {
    std::cout << std::is_integral<int>::value << std::endl;
    using MyType = int;
    using MyConstType = std::add_const<MyType>::type;
    std::cout << std::is_const<MyConstType>::value << "\n";

    int* p = new int(0);
    int x = 10;
    func(p);
    func(x);
    delete p;
}