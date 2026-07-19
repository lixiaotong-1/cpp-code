// 题目：实现一个StringWrapper类，该类内部包含一个std::string对象。要求：
// 1.为StringWrapper类实现移动构造函数和移动赋值运算符。
// 2.提供一个成员函数来显示内部std::string的内容。
// 3.在main函数中创建几个StringWrapper对象，并演示如何通过std::move使用移动语义来传递对象，同时观察移动前后对象的状态。
// 验收标准：
// 1.StringWrapper类应能正确编译并运行。
// 2.移动构造函数和移动赋值运算符应能正确实现移动语义，避免不必要的字符串拷贝。
// 3.通过std::move传递对象后，原对象应处于有效但不可用的状态（可析构但不可预测内容）。
// 4.程序应能输出移动前后的对象状态，以验证移动语义的正确性。
#include <iostream>
#include <string>
class StringWrapper {
public:
    StringWrapper(const std::string& str): str_(str) {
        std::cout << "调用了普通构造函数" << "\n";
    }

    StringWrapper(const StringWrapper& strwrapper) {
        str_ = strwrapper.str_;
        std::cout << "调用了普通拷贝构造函数" << "\n";
    }

    StringWrapper& operator=(const StringWrapper& strwrapper) {
        std::cout << "调用了普通赋值构造函数" << "\n";
        if (this == &strwrapper) {
            return *this;
        }
        str_ = strwrapper.str_;
        return *this;
    }

    StringWrapper(StringWrapper&& strwrapper) noexcept {
        std::cout << "调用了移动构造函数" << "\n";
        str_ = std::move(strwrapper.str_);
    }

    StringWrapper& operator=(const StringWrapper&& strwrapper) noexcept {
        std::cout << "调用了移动赋值函数" << "\n";
        if (this == &strwrapper) {
            return *this;
        }
        str_ = std::move(strwrapper.str_);
        return *this;
    }
    void printStringContent() const {
        if (str_.empty()) {
            std::cout << "空字符串" << "\n";
        } else {
            std::cout << str_ << "\n";
        }
    }
private:
    std::string str_;
};

int main() {
    StringWrapper sw1("第1个字符串对象");
    StringWrapper sw2("第2个字符串对象");
    sw1.printStringContent();
    sw2.printStringContent();
    std::cout << "调用移动构造函数使用sw1构造sw3" << "\n";
    StringWrapper sw3(std::move(sw1));
    sw1.printStringContent();
    sw3.printStringContent();
    std::cout << "调用移动赋值函数使用sw2赋值sw3" << "\n";
    sw3 = std::move(sw2);
    sw1.printStringContent();
    sw2.printStringContent();
}
