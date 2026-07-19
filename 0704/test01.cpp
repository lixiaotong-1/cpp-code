// 题目：抽象类的使用
// 要求：定义一个抽象基类Animal，其中包含纯虚函数makeSound()。
// 定义两个派生类Dog和Cat，分别实现makeSound()函数以输出不同的声音。在main函数中，通过基类指针动态分配内存给Dog和Cat对象，并调用makeSound()函数。
// 最后，释放分配的内存。
// 验收标准：
// 1.Animal类被正确定义为抽象类，包含纯虚函数makeSound()。
// 2.Dog和Cat类正确继承自Animal类，并实现了makeSound()函数。
// 3.在main函数中，成功使用new操作符动态分配了Dog和Cat对象的内存，并通过基类指针调用了makeSound()函数。
// 4.在调用完makeSound()函数后，成功使用delete操作符释放了分配的内存，避免了内存泄漏。
#include <iostream>
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {};
};

class Dog: public Animal {
public:
    void makeSound() override {
        std::cout << "dog make sound" << "\n";
    }
    ~Dog() {
        std::cout << "dog 析构" << "\n";
    }
};

class Cat: public Animal {
public:
    void makeSound() override {
        std::cout << "cat make sound" << "\n";
    }
    ~Cat() {
        std::cout << "cat 析构" << "\n";
    }
};

int main() {
    Animal* p1 = new Dog();
    Animal* p2 = new Cat();
    p1->makeSound();
    p2->makeSound();
    delete p1;
    delete p2;
}