// 题目1：拷贝构造函数
// 要求：定义一个MyClass类，包含一个动态分配的整型数组作为成员。实现拷贝构造函数，确保深拷贝发生。
// 验收标准：
// 1.拷贝构造函数应正确复制动态分配的数组。
// 2.测试显示两个对象具有独立的数组副本。
// #include <iostream>
// class MyClass {
// public:
//     MyClass() {
//         len = 0;
//         arr = nullptr;
//     }
//     MyClass(int size) {
//         if (size > 0) {
//             len = size;
//             arr = new int[len];
//             memset(arr, 0, len * sizeof(int));
//         } else {
//             len = 0;
//             arr = nullptr;
//         }
//     }
//     MyClass(const MyClass& myclass) {
//         if (myclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = myclass.len;
//             arr = new int[len];
//             memcpy(arr, myclass.arr, myclass.len * sizeof(int));
//         }
//     }
//     void printArr() const {
//         if (len == 0 || arr == nullptr) {
//             std::cout << "空数组" << "\n";
//             return;
//         }
//         for (int i = 0; i < len; ++i) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << "\n";
//     }
//     void setIndexVal(int idx, int val) {
//         if (idx >= 0 && idx < len) {
//             arr[idx] = val;
//         }
//     }
//     int* getStartAddr () const {
//         return arr;
//     }
//     ~MyClass() {
//         std::cout << "调用了析构函数" << "\n";
//         delete[] arr;
//     }
// private:
//     int* arr;
//     int len;
// };

// int main() {
//     MyClass arr1(10);
//     arr1.printArr();
//     MyClass arr2(arr1);
//     arr2.printArr();
//     arr1.setIndexVal(2, 10);
//     std::cout << "修改后" << "\n";
//     arr1.printArr();
//     arr2.printArr();
//     std::cout << "两个数组的起始地址不同" << "\n";
//     std::cout << arr1.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";
// }


// // 题目2：移动构造函数
// // 要求：扩展MyClass类，实现移动构造函数。
// // 验收标准：
// // 1.移动构造函数应正确“窃取”源对象的数组，并将源对象的指针设置为nullptr或其他安全值。
// // 2.测试显示移动后源对象处于有效但未定义状态（如指针为空）。
// #include <iostream>
// class MyClass {
// public:
//     MyClass() {
//         len = 0;
//         arr = nullptr;
//     }
//     MyClass(int size) {
//         if (size > 0) {
//             len = size;
//             arr = new int[len];
//             memset(arr, 0, len * sizeof(int));
//         } else {
//             len = 0;
//             arr = nullptr;
//         }
//     }
//     MyClass(MyClass&& otherclass) {
//         len = otherclass.len;
//         arr = otherclass.arr;
//         otherclass.arr = nullptr;
//         otherclass.len = 0;
//     }
//     MyClass(const MyClass& myclass) {
//         if (myclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = myclass.len;
//             arr = new int[len];
//             memcpy(arr, myclass.arr, myclass.len * sizeof(int));
//         }
//     }
//     void printArr() const {
//         if (len == 0 || arr == nullptr) {
//             std::cout << "空数组" << "\n";
//         }
//         for (int i = 0; i < len; ++i) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << "\n";
//     }
//     void setIndexVal(int idx, int val) {
//         if (idx >= 0 && idx < len) {
//             arr[idx] = val;
//         }
//     }
//     int* getStartAddr () const {
//         return arr;
//     }
//     ~MyClass() {
//         std::cout << "调用了析构函数" << "\n";
//         delete[] arr;
//     }
// private:
//     int* arr;
//     int len;
// };

// int main() {
//     MyClass arr1(10);
//     arr1.printArr();
//     MyClass arr2(arr1);
//     arr2.printArr();
//     arr1.setIndexVal(2, 10);
//     std::cout << "修改后" << "\n";
//     arr1.printArr();
//     arr2.printArr();
//     std::cout << "两个数组的起始地址不同" << "\n";
//     std::cout << arr1.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";

//     MyClass arr3(std::move(arr2));
//     std::cout << "用arr3移动构造创建arr3,构造结束后arr2应该为空指针" << "\n";
//     std::cout << arr3.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";
//     arr2.printArr();
//     arr3.printArr();
// }


// 题目3：赋值运算符重载
// 要求：为MyClass类实现赋值运算符重载。
// 验收标准：
// 1.赋值运算符重载应正确处理自赋值情况。
// 2.确保资源被正确管理，避免内存泄漏。
// #include <iostream>
// class MyClass {
// public:
//     MyClass() {
//         len = 0;
//         arr = nullptr;
//     }
//     MyClass(int size) {
//         if (size > 0) {
//             len = size;
//             arr = new int[len];
//             memset(arr, 0, len * sizeof(int));
//         } else {
//             len = 0;
//             arr = nullptr;
//         }
//     }
//     MyClass(MyClass&& otherclass) {
//         len = otherclass.len;
//         arr = otherclass.arr;
//         otherclass.arr = nullptr;
//         otherclass.len = 0;
//     }
//     MyClass(const MyClass& myclass) {
//         if (myclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = myclass.len;
//             arr = new int[len];
//             memcpy(arr, myclass.arr, myclass.len * sizeof(int));
//         }
//     }
//     MyClass& operator=(const MyClass& otherclass) {
//         if (this == &otherclass) {
//             return *this;
//         }
//         delete[] arr;
//         if (otherclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = otherclass.len;
//             arr = new int[len];
//             memcpy(arr, otherclass.arr, len * sizeof(int));
//         }
//         return *this;
//     }
//     void printArr() const {
//         if (len == 0 || arr == nullptr) {
//             std::cout << "空数组" << "\n";
//             return;
//         }
//         for (int i = 0; i < len; ++i) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << "\n";
//     }
//     void setIndexVal(int idx, int val) {
//         if (idx >= 0 && idx < len) {
//             arr[idx] = val;
//         }
//     }
//     int* getStartAddr () const {
//         return arr;
//     }
//     ~MyClass() {
//         std::cout << "调用了析构函数" << "\n";
//         delete[] arr;
//     }
// private:
//     int* arr;
//     int len;
// };

// int main() {
//     MyClass arr1(10);
//     arr1.printArr();
//     MyClass arr2(arr1);
//     arr2.printArr();
//     arr1.setIndexVal(2, 10);
//     std::cout << "修改后" << "\n";
//     arr1.printArr();
//     arr2.printArr();
//     std::cout << "两个数组的起始地址不同" << "\n";
//     std::cout << arr1.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";

//     MyClass arr3(std::move(arr2));
//     std::cout << "用arr3移动构造创建arr3,构造结束后arr2应该为空指针" << "\n";
//     std::cout << arr3.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";
//     arr2.printArr();
//     arr3.printArr();

//     std::cout << "赋值构造函数测试" << "\n";
//     MyClass arr4(8);
//     std::cout << "赋值前" << "\n";
//     arr4.printArr();
//     arr1.printArr();
//     arr4 = arr1;
//     std::cout << "赋值后" << "\n";
//     arr4.printArr();
//     arr1.printArr();
//     std::cout << "arr3,arr4两个数组的起始地址不同" << "\n";
//     std::cout << arr4.getStartAddr() << "\n";
//     std::cout << arr1.getStartAddr() << "\n";
// }

// // 题目4：移动赋值运算符重载
// // 要求：为MyClass类实现移动赋值运算符重载。
// // 验收标准：
// // 1.移动赋值运算符重载应正确“窃取”右值对象的资源，并将右值对象的指针设置为nullptr或其他安全值。
// // 2.测试显示移动赋值后右值对象处于有效但未定义状态（如指针为空）。
// #include <iostream>
// class MyClass {
// public:
//     MyClass() {
//         len = 0;
//         arr = nullptr;
//     }
//     MyClass(int size) {
//         if (size > 0) {
//             len = size;
//             arr = new int[len];
//             memset(arr, 0, len * sizeof(int));
//         } else {
//             len = 0;
//             arr = nullptr;
//         }
//     }
//     MyClass(MyClass&& otherclass) {
//         len = otherclass.len;
//         arr = otherclass.arr;
//         otherclass.arr = nullptr;
//         otherclass.len = 0;
//     }
//     MyClass(const MyClass& myclass) {
//         if (myclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = myclass.len;
//             arr = new int[len];
//             memcpy(arr, myclass.arr, myclass.len * sizeof(int));
//         }
//     }
//     MyClass& operator=(const MyClass& otherclass) {
//         if (this == &otherclass) {
//             return *this;
//         }
//         delete[] arr;
//         if (otherclass.len == 0) {
//             len = 0;
//             arr = nullptr;
//         } else {
//             len = otherclass.len;
//             arr = new int[len];
//             memcpy(arr, otherclass.arr, len * sizeof(int));
//         }
//         return *this;
//     }
//     MyClass& operator=(MyClass&& otherclass) {
//         if (this == &otherclass) {
//             return *this;
//         }
//         delete[] arr;
//         len = otherclass.len;
//         arr = otherclass.arr;
//         otherclass.len = 0;
//         otherclass.arr = nullptr;
//         return *this;
//     }
//     void printArr() const {
//         if (len == 0 || arr == nullptr) {
//             std::cout << "空数组" << "\n";
//             return;
//         }
//         for (int i = 0; i < len; ++i) {
//             std::cout << arr[i] << " ";
//         }
//         std::cout << "\n";
//     }
//     void setIndexVal(int idx, int val) {
//         if (idx >= 0 && idx < len) {
//             arr[idx] = val;
//         }
//     }
//     int* getStartAddr () const {
//         return arr;
//     }
//     ~MyClass() {
//         std::cout << "调用了析构函数" << "\n";
//         delete[] arr;
//     }
// private:
//     int* arr;
//     int len;
// };

// int main() {
//     MyClass arr1(10);
//     arr1.printArr();
//     MyClass arr2(arr1);
//     arr2.printArr();
//     arr1.setIndexVal(2, 10);
//     std::cout << "修改后" << "\n";
//     arr1.printArr();
//     arr2.printArr();
//     std::cout << "两个数组的起始地址不同" << "\n";
//     std::cout << arr1.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";

//     MyClass arr3(std::move(arr2));
//     std::cout << "用arr3移动构造创建arr3,构造结束后arr2应该为空指针" << "\n";
//     std::cout << arr3.getStartAddr() << "\n";
//     std::cout << arr2.getStartAddr() << "\n";
//     arr2.printArr();
//     arr3.printArr();

//     std::cout << "赋值构造函数测试" << "\n";
//     MyClass arr4(8);
//     std::cout << "赋值前" << "\n";
//     arr4.printArr();
//     arr1.printArr();
//     arr4 = arr1;
//     std::cout << "赋值后" << "\n";
//     arr4.printArr();
//     arr1.printArr();
//     std::cout << "arr3,arr4两个数组的起始地址不同" << "\n";
//     std::cout << arr4.getStartAddr() << "\n";
//     std::cout << arr1.getStartAddr() << "\n";

//     std::cout << "移动赋值函数测试" << "\n";
//     MyClass arr5(8);
//     MyClass arr6(10);
//     arr6.setIndexVal(0, 20);
//     std::cout << "移动赋值前" << "\n";
//     arr5.printArr();
//     arr6.printArr();
//     arr5 = std::move(arr6);
//     std::cout << "移动赋值后" << "\n";
//     arr5.printArr();
//     arr6.printArr();
//     std::cout << "arr5,arr6两个数组的起始地址不同" << "\n";
//     std::cout << arr5.getStartAddr() << "\n";
//     std::cout << arr6.getStartAddr() << "\n";
// }

// 题目5：综合测试
// 要求：编写一个测试程序，创建MyClass对象，并测试拷贝构造、移动构造、赋值运算符重载和移动赋值运算符重载的行为。
// 验收标准：
// 1.验证所有构造函数和赋值运算符的行为符合预期。
// 2.确保资源被正确管理，没有内存泄漏。
// 3.验证自赋值情况下的正确性。
#include <iostream>
class MyClass {
public:
    MyClass() {
        len = 0;
        arr = nullptr;
    }
    MyClass(int size) {
        if (size > 0) {
            len = size;
            arr = new int[len];
            memset(arr, 0, len * sizeof(int));
        } else {
            len = 0;
            arr = nullptr;
        }
    }
    MyClass(MyClass&& otherclass) noexcept {
        len = otherclass.len;
        arr = otherclass.arr;
        otherclass.arr = nullptr;
        otherclass.len = 0;
    }
    MyClass(const MyClass& myclass) {
        if (myclass.len == 0) {
            len = 0;
            arr = nullptr;
        } else {
            len = myclass.len;
            arr = new int[len];
            memcpy(arr, myclass.arr, myclass.len * sizeof(int));
        }
    }
    MyClass& operator=(const MyClass& otherclass) {
        if (this == &otherclass) {
            return *this;
        }
        delete[] arr;
        if (otherclass.len == 0) {
            len = 0;
            arr = nullptr;
        } else {
            len = otherclass.len;
            arr = new int[len];
            memcpy(arr, otherclass.arr, len * sizeof(int));
        }
        return *this;
    }
    MyClass& operator=(MyClass&& otherclass) noexcept {
        if (this == &otherclass) {
            return *this;
        }
        delete[] arr;
        len = otherclass.len;
        arr = otherclass.arr;
        otherclass.len = 0;
        otherclass.arr = nullptr;
        return *this;
    }
    void printArr() const {
        if (len == 0 || arr == nullptr) {
            std::cout << "空数组" << "\n";
            return;
        }
        for (int i = 0; i < len; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    void setIndexVal(int idx, int val) {
        if (idx >= 0 && idx < len) {
            arr[idx] = val;
        }
    }
    int* getStartAddr () const {
        return arr;
    }
    ~MyClass() {
        std::cout << "调用了析构函数" << "\n";
        delete[] arr;
    }
private:
    int* arr;
    int len;
};

int main() {
    MyClass arr1(10);
    arr1.printArr();
    MyClass arr2(arr1);
    arr2.printArr();
    arr1.setIndexVal(2, 10);
    std::cout << "修改后" << "\n";
    arr1.printArr();
    arr2.printArr();
    std::cout << "两个数组的起始地址不同" << "\n";
    std::cout << arr1.getStartAddr() << "\n";
    std::cout << arr2.getStartAddr() << "\n";

    MyClass arr3(std::move(arr2));
    std::cout << "用arr3移动构造创建arr3,构造结束后arr2应该为空指针" << "\n";
    std::cout << arr3.getStartAddr() << "\n";
    std::cout << arr2.getStartAddr() << "\n";
    arr2.printArr();
    arr3.printArr();

    std::cout << "赋值构造函数测试" << "\n";
    MyClass arr4(8);
    std::cout << "赋值前" << "\n";
    arr4.printArr();
    arr1.printArr();
    arr4 = arr1;
    std::cout << "赋值后" << "\n";
    arr4.printArr();
    arr1.printArr();
    std::cout << "arr3,arr4两个数组的起始地址不同" << "\n";
    std::cout << arr4.getStartAddr() << "\n";
    std::cout << arr1.getStartAddr() << "\n";

    std::cout << "移动赋值函数测试" << "\n";
    MyClass arr5(8);
    MyClass arr6(10);
    arr6.setIndexVal(0, 20);
    std::cout << "移动赋值前" << "\n";
    arr5.printArr();
    arr6.printArr();
    arr5 = std::move(arr6);
    std::cout << "移动赋值后" << "\n";
    arr5.printArr();
    arr6.printArr();
    std::cout << "arr5,arr6两个数组的起始地址不同" << "\n";
    std::cout << arr5.getStartAddr() << "\n";
    std::cout << arr6.getStartAddr() << "\n";

    std::cout << "自赋值情况" << "\n";
    MyClass arr7(10);
    MyClass arr8(10);
    arr7.setIndexVal(0, 20);
    arr8.setIndexVal(1, 20);
    std::cout << "移动赋值前" << "\n";
    arr7.printArr();
    arr8.printArr();
    std::cout << "arr7,arr8数组的起始地址" << "\n";
    std::cout << arr7.getStartAddr() << "\n";
    std::cout << arr8.getStartAddr() << "\n";
    std::cout << "移动自赋值后" << "\n";
    arr7 = std::move(arr7);
    arr7.printArr();
    std::cout << "普通自赋值后" << "\n";
    arr8 = arr8;
    arr8.printArr();
    std::cout << "arr7,arr8数组的起始地址" << "\n";
    std::cout << arr7.getStartAddr() << "\n";
    std::cout << arr8.getStartAddr() << "\n";
}
