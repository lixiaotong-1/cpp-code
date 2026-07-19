// 题目4：使用列表初始化定义变量
// 要求：定义一个结构体Point，包含两个成员变量x和y，类型为int。然后，在main函数中，使用列表初始化定义一个Point对象，并初始化其成员变量。
// 验收标准：
// 1.Point结构体定义正确，包含x和y两个成员变量。
// 2.在main函数中，成功使用列表初始化定义了Point对象，并正确初始化了其成员变量。
// #include <iostream>

// class Point {
// public:
//     Point(int x = 0, int y = 0):x(x), y(y) {}
//     void printInfo() const {
//         std::cout << x << "," << y << "\n";
//     }
// private:
//     int x;
//     int y;
// };

// int main() {
//     Point p1{3, 4};
//     p1.printInfo();
// }

// 要求：定义一个std::vector<int>对象，并使用列表初始化来初始化该容器，包含元素{1, 2, 3, 4, 5}。然后，遍历并打印该容器的所有元素。
// 验收标准：
// 1.std::vector<int>对象被正确定义并初始化。
// 2.容器中的元素被正确遍历并打印出来。
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> v = {1, 2, 3, 4, 5};
//     for (const auto e: v) {
//         std::cout << e << " ";
//     }
//     std::cout << "\n";
// }


// 要求：定义一个类Box，包含两个构造函数：一个接受两个int参数（表示宽度和高度），另一个接受一个std::initializer_list<int>参数（表示多个尺寸）。
// 然后，在main函数中，分别使用这两种方式创建Box对象，并验证它们的行为。
// 验收标准：
// 1.Box类定义正确，包含两个构造函数。
// 2.在main函数中，能够使用不同的方式（直接传递两个整数和使用列表初始化）来创建Box对象。
// 3.验证这两种方式都能正确调用对应的构造函数，并表现出预期的行为（例如，可以通过打印构造函数接收到的参数来验证）。
#include <iostream>
#include <initializer_list>
#include <vector>

class Box {
public:
    Box(int w, int h): width(w), height(h) {
        std::cout << "w, h 初始化, w = " << w << ", h = " << h << "\n";
    }
    Box(std::initializer_list<int> lst): sizes(lst) {
        std::cout << "初始化列表初始化" << "\n";
        for (const auto e: sizes) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
private:
    int width;
    int height;
    std::vector<int> sizes;
};

int main() {
    Box box1(2, 3);
    Box box2{1, 2, 3, 4, 5, 6};
}