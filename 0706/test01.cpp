// 题目1：基本异常处理
// 编写一个C++程序，其中包含一个函数divide，该函数接收两个整数作为参数，并返回它们的除法结果。
// 如果除数为0，则该函数应抛出一个std::runtime_error异常。在main函数中，调用divide函数并捕获可能抛出的异常，打印出异常信息。
// 验收标准：
// 1.程序应能正确执行除法运算，并在除数为0时抛出std::runtime_error异常。
// 2.main函数应能捕获并打印出异常信息。
// #include <iostream>
// #include <stdexcept>

// double divide(int a, int b) {
//     if (b == 0) {
//         throw std::runtime_error("除数不能为零！");
//     }
//     return static_cast<double>(a) / b;
// }

// int main() {
//     try {
//         divide(3, 0);
//     } catch (const std::runtime_error& e) {
//         std::cerr << e.what() << "\n";
//     }
//     try {
//         double res = divide(4, 5);
//         std::cout << "res = " << res << "\n";
//     } catch (const std::runtime_error& e) {
//         std::cerr << e.what() << "\n";
//     }
// }

// 题目2：自定义异常处理
// 定义一个自定义异常类DivideByZeroException，该类继承自std::exception，并实现what()方法以返回“Cannot divide by zero”作为异常描述。
// 然后，修改题目1中的divide函数，在除数为0时抛出DivideByZeroException异常。最后，在main函数中捕获并处理这个自定义异常。
// 验收标准：
// 1.DivideByZeroException类应正确实现，并能在除数为0时被抛出。
// 2.main函数应能捕获并打印出DivideByZeroException的自定义异常信息。
// #include <iostream>
// #include <stdexcept>
// #include <exception>
// #include <string>
// class DivideByZeroException: public std::exception {
// public:
//     DivideByZeroException(const std::string& chs): message(chs) {}
//     virtual const char* what() const noexcept override {
//         return message.c_str();
//     }
//     virtual ~DivideByZeroException() noexcept = default;
// private:
//     std::string message;
// };

// double divide(int a, int b) {
//     if (b == 0) {
//         throw DivideByZeroException("除数不能为0！");
//     }
//     return static_cast<double>(a) / b;
// }

// int main() {
//     try {
//         divide(3, 0);
//     } catch (const DivideByZeroException& e) {
//         std::cerr << e.what() << "\n";
//     }
//     try {
//         double res = divide(4, 5);
//         std::cout << "res = " << res << "\n";
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << "\n";
//     }
// }

// 题目3：多层异常处理
// 编写一个程序，该程序包含三个函数：A、B和C。函数A调用函数B，函数B调用函数C。函数C负责执行某个可能抛出异常的操作（如题目1或题目2中的除法运算）。
// 如果发生异常，异常应能被A函数中的try-catch块捕获并处理。
// 验收标准：
// 1.程序应能正确地在多层函数调用中传播异常。
// 2.异常应能被最外层的try-catch块（在A函数中）捕获并处理。
// 3.应确保在捕获异常后，程序能够继续执行其他任务。
#include <iostream>
#include <stdexcept>
class DivideByZeroException: public std::exception {
public:
    DivideByZeroException(const std::string& chs): message(chs) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
    virtual ~DivideByZeroException() noexcept = default;
private:
    std::string message;
};

double divide(int a, int b) {
    if (b == 0) {
        throw DivideByZeroException("除数不能为0！");
    }
    return static_cast<double>(a) / b;
}

double B(int a, int b) {
    std::cout << "进入B函数" << '\n';
    double res = divide(a, b);
    std::cout << "B函数：res = " << res << "\n";
    return res;
}

double A(int a, int b) {
    std::cout << "进入A函数" << "\n";
    try {
        double res = B(a, b);
        std::cout << "A函数：res = " << res << "\n";
        return res;
    } catch (const DivideByZeroException& e) {
        std::cerr << e.what() << "\n";
    }
    std::cout << "A函数执行结束" << "\n";
}

int main() {
    double res = A(3, 0);
    std::cout << "异常调用结束" << "\n";
    res = A(3, 2);
    std::cout << "正常调用结束" << "\n";
}