// 类中包含私有成员变量：姓名（std::string name）、年龄（int age）、学号（std::string id）。
// 提供公有的成员函数：
// 构造函数，用于初始化学生的姓名、年龄和学号。
// getName()和setName(const std::string& newName)成员函数，用于获取和设置学生的姓名。
// getAge()和setAge(int newAge)成员函数，用于获取和设置学生的年龄。
// getID()和setID(const std::string& newID)成员函数，用于获取和设置学生的学号。
// display()成员函数，用于打印学生的姓名、年龄和学号。
// 验收标准：
// Student类应包含所有指定的私有成员变量和公有成员函数。
// 成员函数应能正确地对私有成员变量进行访问和操作。
// display()函数应能正确打印出学生的姓名、年龄和学号。


// 编写一个main函数，在其中创建至少两个Student对象，并通过公有成员函数设置和获取它们的属性，最后通过display()函数打印出它们的信息。
// 验收标准：
// main函数中应能正确创建Student对象，并通过公有成员函数对对象进行操作。
// 应能正确打印出每个Student对象的姓名、年龄和学号。
// 这两个题目覆盖了C++中类的封装的基本概念和实际应用，能够有效地检验对封装相关知识点的理解和掌握程度。
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Student {
private:
    string name_;
    int age_;
    string id_;
public:
    Student(const string& name, int age, const string& id): name_(name), age_(age), id_(id) {}
    Student() = default;
    const string& GetName() const {
        return name_;
    }
    void SetName(const string& new_name) {
        name_ = new_name;
    }
    int GetAge() const {
        return age_;
    }
    void SetAge(int new_age) {
        age_ = new_age;
    }
    const string& GetId() const {
        return id_;
    }
    void SetId(const string& new_id) {
        id_ = new_id;
    }
    void Display() const {
        cout << "name is " << name_ << "\n";
        cout << "age is " << age_ << "\n";
        cout << "id is " << id_ << "\n";
    }
};

int main()
{
    Student stu("张三", 20, "16001818");
    stu.Display();
    stu.SetName("李四");
    stu.SetAge(80);
    stu.SetId("90909090");
    stu.Display();
    string name = stu.GetName();
    int age = stu.GetAge();
    string id = stu.GetId();
    cout << name << "," << age << "," << id << "\n";
    cout << "==========stu1 info==========" << "\n";
    Student stu1;
    stu1.SetName("lixiaotong");
    stu1.SetAge(78);
    stu1.SetId("hello,world");
    stu1.Display();
}