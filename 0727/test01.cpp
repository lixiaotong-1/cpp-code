// 题目1：std::string的基本操作
// 要求：编写一个C++程序，定义一个std::string对象，并使用append(), insert(), erase(), find(), replace()等成员函数对其进行操作。
// 具体地，先定义一个包含初始字符串的std::string对象，然后依次执行以下操作：
// 在字符串末尾追加一个字符串。
// 在指定位置插入一个子字符串。
// 删除字符串中的某个子字符串（如果存在）。
// 查找字符串中某个子字符串的位置（并打印）。
// 替换字符串中的某个子字符串为另一个字符串。
// 验收标准：
// 程序能够正确创建std::string对象，并初始化。
// 程序能够正确执行上述所有字符串操作。
// 程序能够正确打印出每一步操作后的字符串内容。
// #include <iostream>
// #include <string>

// int main() {
//     std::string str("1234567");
//     std::cout << "初始字符串 " << str << "\n";
//     str.append("8");
//     std::cout << "结尾加上8之后 " << str << "\n";
//     str.insert(str.begin() + 2, '0');
//     std::cout << "下标2的地方插入0 " << str << "\n";
//     // 删除字符串中的某个子字符串
//     std::string target_del = "567";
//     size_t delidx = str.find(target_del);
//     if (delidx != std::string::npos) {
//         str.erase(delidx, target_del.size());
//     } 
//     std::cout << "删除567之后 " << str << "\n";
//     size_t target_idx = str.find("48");
//     if (target_idx != std::string::npos) {
//         std::cout << "48子字符串的起始下标为 " << target_idx << "\n";
//     } else {
//         std::cout << "not found" << "\n";
//     }
//     std::string target_replce = "03";
//     size_t start_idx = str.find(target_replce);
//     if (start_idx != std::string::npos) {
//         str.replace(start_idx, target_replce.size(), "hello");
//     }
//     std::cout << "将03替换为hello之后 " << str << "\n";
// }


// 题目2：std::string与C风格字符串的转换
// 要求：编写一个C++程序，包含以下功能：
// 定义一个C风格字符串（例如，通过const char*）。
// 将该C风格字符串转换为std::string对象，并打印出来。
// 修改std::string对象的内容。
// 将修改后的std::string对象转换回C风格字符串，并打印出来（注意，这里可能需要使用c_str()成员函数，并了解c_str()返回的指针的有效期）。
// 验收标准：
// 程序能够正确地将C风格字符串转换为std::string对象，并打印转换结果。
// 程序能够正确地修改std::string对象的内容。
// 程序能够正确地将修改后的std::string对象转换回C风格字符串，并打印转换结果。
// 程序理解并正确处理了c_str()返回的指针的有效期问题。
#include <iostream>
#include <string>

int main() {
    const char* const_str = "hello, world~";
    std::string new_str(const_str);
    std::cout << "original string " << new_str << "\n";
    new_str = "hello world";
    std::cout << "after modify " << new_str << "\n";
    const char* tmp_ptr = new_str.c_str();
    std::cout << "c_ctr() = " << tmp_ptr << "\n";

    new_str.append("1234568736524");
    const char* cur_ptr = new_str.c_str();
    std::cout << "after modify c_str() = " << cur_ptr << "\n";
    // 之前的指针已经失效
    std::cout << "before modify c_str() = " << tmp_ptr << "\n";
}