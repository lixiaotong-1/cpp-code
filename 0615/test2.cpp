// 定义一个包含嵌套命名空间的复杂结构，比如Geometry::Shapes，
// 在Shapes命名空间中定义两个函数calculateArea和calculatePerimeter（假设为圆形，需要半径作为参数）。
// 在main函数中，使用using指令引入Geometry::Shapes命名空间中的所有元素，并调用这两个函数。
#include <iostream>

namespace Geometry {
    namespace Shapes {
        const double PI = 3.1415926;
        double calculateArea(double r)
        {
            return PI * r * r;
        }
        double calculatePerimeter(double r)
        {
            return 2 * PI * r;
        }
    }
}

int main()
{
    using namespace Geometry::Shapes;
    double r = 2;
    double area = calculateArea(2);
    double perimeter = calculatePerimeter(2);
    std::cout << "area = " << area << ", perimeter = " << perimeter << "\n";
}