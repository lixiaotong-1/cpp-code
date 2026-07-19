// 要求：定义一个class，它包含一个动态分配的整型数组作为成员。
// 为这个类实现构造函数来初始化数组，并实现析构函数来释放数组。在main函数中创建该类的对象，并在对象生命周期结束后观察内存是否被正确释放。
// 验收标准：
// 构造函数应正确初始化动态分配的数组。
// 析构函数应释放动态分配的内存，防止内存泄露。
#include <iostream>
using std::cout;

class Base {
    private:
        int* ptr_;
        int len_;
    public:
        Base() {
            ptr_ = nullptr;
            len_ = 0;
        }
        Base(int nums[], int len) {
            ptr_ = new int[len];
            memcpy(ptr_, nums, sizeof(int) * len);
            len_ = len;
        }
        ~Base() {
            cout << "调用了析构函数" << "\n";
            if (ptr_ != nullptr) {
                delete ptr_;
                ptr_ = nullptr;
                len_ = 0;
            } else {
                len_ = 0;
            }
        }
        void Display() const {
            for (int i = 0; i < len_; ++i) {
                cout << ptr_[i] << " ";
            }
            cout << "\n";
        }
};

int main()
{
    Base base;
    base.Display();
    int nums[] = {1, 2, 3, 4, 5};
    Base base1(nums, 5);
    base1.Display();
}