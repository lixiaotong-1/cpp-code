// 要求：定义一个Person类，包含姓名（name）和年龄（age）作为私有成员变量，以及相应的构造函数、析构函数、设置和获取成员变量的成员函数。
// 在main函数中创建Person对象，并测试这些成员函数。
// 验收标准：
// 类定义正确，包含私有成员变量和公有成员函数。
// 构造函数和析构函数被正确调用。
// 成员变量的值能够通过公有成员函数正确设置和获取。
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

int main()
{
    Person person;
    person.SetPerson("lixiaotong", 28);
    string name = person.GetPersonName();
    int age = person.GetPersonAge();
    cout << "person name:" << name << "\n";
    cout << "person age:" << age << "\n";
}