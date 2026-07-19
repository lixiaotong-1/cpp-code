// 定义一个基类Shape，包含至少一个纯虚函数draw()。然后定义两个派生类Circle和Rectangle，分别实现draw()函数以绘制圆形和矩形。
// 在main函数中，通过基类指针数组来存储不同形状的对象，并调用它们的draw()函数。
// 验收标准：
// 基类Shape包含纯虚函数draw()。
// 派生类Circle和Rectangle正确实现了draw()函数。
// 在main函数中，通过基类指针数组能够正确调用不同派生类对象的draw()函数，实现多态。
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Shape {
    public:
        virtual void draw() = 0;
};

class Circle: public Shape {
    public:
        void draw() {
            cout << "circle draw" << "\n";
        }
};

class Rectangle: public Shape {
    public:
        void draw() {
            cout << "rectangle draw" << "\n";
        }
};

int main()
{
    Shape* shape_ptr[2] = {nullptr, nullptr};
    Circle cirle;
    Rectangle rectangle;
    shape_ptr[0] = &cirle;
    shape_ptr[1] = &rectangle;
    for (int i = 0; i < 2; ++i) {
        shape_ptr[i]->draw();
    }
}