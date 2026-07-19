// 要求：定义一个基类Vehicle，包含成员变量color。然后定义两个派生类Car和Boat，它们分别继承自Vehicle。
// 再定义一个类AmphibiousCar，它同时继承自Car和Boat，使用虚拟继承解决菱形继承问题。在main函数中创建AmphibiousCar对象，并设置其颜色。
// 验收标准：
// 1.Vehicle、Car、Boat和AmphibiousCar类定义正确，AmphibiousCar使用了虚拟继承。
// 2.AmphibiousCar对象能够正确设置并访问color成员变量，没有因为菱形继承而导致数据冗余或不一致。
#include <iostream>
#include <string>
class Vehicle {
public:
    std::string color;
    Vehicle(std::string s): color(s) {}
};

class Car: virtual public Vehicle {
public:
    Car(std::string s): Vehicle(s) {}
};

class Boat: virtual public Vehicle {
public:
    Boat(std::string s): Vehicle(s) {}
};

class AmphibiousCar: public Car, Boat {
public:
    AmphibiousCar(std::string s): Vehicle(s), Car(s), Boat(s) {}
};

int main() {
    AmphibiousCar* p = new AmphibiousCar("red");
    Car* pcar = (Car*)p;
    Boat* pboat = (Boat*)p;
    std::cout << pcar->color << "," << pboat->color << "\n";
}