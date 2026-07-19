// 要求：定义一个基类Shape，包含一个虚析构函数。然后定义两个派生类Circle和Rectangle，
// 它们分别实现了自己的析构函数（除了调用基类的析构函数外，还可以执行一些清理工作）。在main函数中，
// 使用基类指针数组来存储Circle和Rectangle对象，并遍历该数组以删除所有对象。
// 验收标准：
// 1.Shape类正确声明了虚析构函数。
// 2.Circle和Rectangle类正确实现了析构函数，并在其中执行了必要的清理工作。
// 3.在main函数中，成功使用基类指针数组存储了派生类对象，并在遍历过程中正确调用了每个对象的析构函数，
// 确保了资源的正确释放。注意检查是否有内存泄漏或析构顺序问题。
#include <iostream>

class Shape {
public:
    Shape() {
        std::cout << "Shape construction" << "\n";
    }
    virtual ~Shape() {
        std::cout << "shape deconstruction." << "\n";
    }
};

class Circle: public Shape {
public:
    double r;
    Circle(double r): r(r) {
        std::cout << "circle的构造函数执行" << "\n";
    }
    ~Circle() {
        std::cout << "circle的析构函数执行" << "\n";
    }
};

class Rectangle: public Shape {
public:
    double width;
    double height;
    Rectangle(double w, double h): width(w), height(h) {
        std::cout << "Rectangle的构造函数执行" << "\n";
    }
    ~Rectangle() {
        std::cout << "Rectangle的析构函数执行" << "\n";
    }
};

int main() {
    Shape* arr[2];
    arr[0] = new Circle(3.0);
    arr[1] = new Rectangle(2, 4);

    delete arr[0];
    delete arr[1];
}