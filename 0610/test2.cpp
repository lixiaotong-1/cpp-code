// 要求：定义一个Student类，继承自Person类（见题目1），并添加学号（studentID）
// 作为私有成员变量，以及相应的构造函数、析构函数、设置和获取学号的成员函数。在main函数中创建Student对象，并测试这些成员函数。
// 验收标准：
// Student类正确继承自Person类。
// Student类能够正确设置和获取Person类的成员变量以及自己的学号。
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Person {
    private:
        string name_;
        int age_;
    public:
        Person() {
            name_ = "";
            age_ = 0;
        }
        ~Person() {}
        Person(const string& name, int age): name_(name), age_(age) {}
        void SetPerson(const string& name, int age) {
            name_ = name;
            age_ = age;
        }
        const string& GetPersonName() const {
            return name_;
        }
        int GetPersonAge() const {
            return age_;
        }
};

class Student: public Person {
    private:
        int studentID_;
    public:
        Student() {
            studentID_ = 0;
        };
        ~Student() {};
        Student(string name, int age, int studentid): Person(name, age), studentID_(studentid) {}
        void SetStudentId(int id) {
            studentID_ = id;
        }
        int GetStudentId() const {
            return studentID_;
        }
};

int main()
{
    Student stu;
    cout << stu.GetPersonName() << " " << stu.GetPersonAge() << " " << stu.GetStudentId() << "\n";
    stu.SetPerson("lixiaotong", 28);
    stu.SetStudentId(161);
    cout << stu.GetPersonName() << " " << stu.GetPersonAge() << " " << stu.GetStudentId() << "\n";

    Student stu2("liming", 80, 980);
    cout << stu2.GetPersonName() << " " << stu2.GetPersonAge() << " " << stu2.GetStudentId() << "\n";
}