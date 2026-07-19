// 题目1：复数类的加法操作符重载
// 要求：定义一个复数类Complex，包含实部和虚部两个成员变量。重载加法操作符+，使得两个Complex对象相加时，
// 能够返回一个新的Complex对象，其实部和虚部分别为两个操作数实部和虚部的和。
// 验收标准：
// 1.Complex类定义正确，包含实部和虚部成员变量。
// 2.成功重载了加法操作符+，使其能够接收两个Complex对象作为参数，并返回一个新的Complex对象。
// 3.提供了测试代码，展示了如何使用重载的加法操作符对两个Complex对象进行加法运算，并验证了结果的正确性。
// #include <iostream>
// class Complex {
// public:
//     int real;
//     int image;
//     Complex(int re = 0, int im = 0): real(re), image(im) {}
//     ~Complex() {}
//     Complex operator+(const Complex& complex) const {
//         int newreal = real + complex.real;
//         int newimage = image + complex.image;
//         return Complex(newreal, newimage);
//     }
//     void printComplex() {
//         if (image >= 0) {
//             std::cout << real << "+" << image << "i" << "\n";
//         } else {
//             std::cout << real << "-" << image << "i" << "\n";
//         }
//     }
// };

// int main() {
//     Complex com(1, 2);
//     Complex com2(2, 3);
//     Complex res = com + com2;
//     res.printComplex();
// }

// 题目2：矩阵类的乘法操作符重载
// 要求：定义一个矩阵类Matrix，包含矩阵的行数、列数和存储矩阵元素的二维数组。重载乘法操作符*，
// 使得两个Matrix对象相乘时，能够返回一个新的Matrix对象，其元素为两个操作数矩阵对应元素乘积的和（即矩阵乘法）。
// 注意：为了简化问题，可以假设两个矩阵的维度是兼容的，即第一个矩阵的列数等于第二个矩阵的行数。
// 验收标准：
// 1.Matrix类定义正确，包含行数、列数和二维数组成员变量。
// 2.成功重载了乘法操作符*，使其能够接收两个Matrix对象作为参数，并返回一个新的Matrix对象。
// 3.提供了测试代码，展示了如何使用重载的乘法操作符对两个Matrix对象进行乘法运算，并验证了结果的正确性。
#include <iostream>
#include <vector>
class Matrix {
private:
    int row;
    int col;
    std::vector<std::vector<int>> v;

public:
    Matrix(int r, int c): row(r), col(c), v(row, std::vector<int>(col, 0)) {}
    Matrix(int r, int c, const std::vector<std::vector<int>>& arr): row(r), col(c), v(row, std::vector<int>(col, 0)) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                v[i][j] = arr[i][j];
            }
        }
    }

    int calSumFun(const Matrix& mat2, int i, int j) const {
        int res = 0;
        for (int k = 0; k < col; k++) {
            res += v[i][k] * mat2.v[k][j];
        }
        return res;
    }
    
    Matrix operator*(const Matrix& mat) const {
        Matrix res(row, mat.col);
        for(int i = 0; i < res.row; ++i) {
            for (int j = 0; j < res.col; ++j) {
                res.v[i][j] = calSumFun(mat, i, j);
            }
        }
        return res;
    }
    void printMatrix() const {
        for (const auto& elem: v) {
            for (const auto e: elem) {
                std:: cout << e << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    std::vector<std::vector<int>> v1(2, std::vector<int>(3, 0));
    std::vector<std::vector<int>> v2(3, std::vector<int>(4, 0));
    v1 = {{1, 2, 3}, {3, 4, 5}};
    v2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Matrix matrix1(2, 3, v1);
    Matrix matrix2(3, 4, v2);
    Matrix res = matrix1 * matrix2;
    res.printMatrix();
}