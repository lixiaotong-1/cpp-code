// 题目1：单继承与多态
// 要求：定义一个基类Animal，包含虚函数makeSound()。然后定义两个派生类Dog和Cat，分别重写makeSound()函数以输出不同的声音。
// 在main函数中创建Dog和Cat的对象，并使用基类指针指向这些对象，调用makeSound()函数以展示多态性。
// 验收标准：
// 1.Animal类正确声明了虚函数makeSound()。
// 2.Dog和Cat类正确重写了makeSound()函数。
// 3.在main函数中，成功使用基类指针指向派生类对象，并调用了makeSound()函数，输出了正确的声音。
#include <iostream>

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}
    virtual void makeSound() {
        std::cout << "animal make sound" << "\n";
    }
};

class Dog: public Animal{
public:
    Dog() {}
    ~Dog() {}
    void makeSound() {
        std::cout << "dog make sound" << "\n";
    }
};

class Cat: public Animal{
public:
    Cat() {}
    ~Cat() {}
    void makeSound() {
        std::cout << "cat make sound" << "\n";
    }
};

int main() {
    Animal* ptr = new Dog();
    Animal* ptr1 = new Cat();
    ptr->makeSound();
    ptr1->makeSound();
    return 0;
}