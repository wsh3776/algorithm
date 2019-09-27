// 析构函数就是在构造函数前加一个~ 用来销毁对象
#include <iostream>

using namespace std;

class Human {
public:  // 公有的
    Human() {
        age_ = 15;
    }

    // Human(int age, bool gender) {  // 重载
    //     age_ = age;
    //     gender_ = gender;
    // }

    Human(int age, bool gender)
        : age_(age), gender_(gender) {

    }

    // 析构函数——销毁对象 main函数执行完后就会被销毁
    ~Human() {
        cout << "A human gone..." << endl;
    }

    void walk() {  // 成员函数
        cout << name_ << " is walking..." << endl;
    }

    void say(string content) {
        cout << name_ << " says" << content << endl;
    }

    // Get/Set函数
    string get_name() const {
        return name_;
    }

    void set_name(string name) {
        name_ = name;
    }

    int get_age() const {  //年龄设为只读，不能被更改
        return age_;
    }

    void grow() {
        age_ ++;
    }
    bool get_gender() const {
        return gender_;
    }

    void set_gender(bool gender) {
        gender_ = gender;
    }
    // private的成员不能通过.运算符来访问，只能通过public中的成员函数来访问，比如get，set函数理解为只读或可写得意思
private:
    string name_;  // 成员变量
    int age_;
    bool gender_;  // true if male
};


int main() {
    // 调用方法 对象名.成员名
    Human lihua(25, true), hanmeimei; // 有两个重载的函数

    lihua.set_name("李华");  // set 写数据
    // lihua.set_age(30);    // age是只读的数据
    lihua.set_gender(true);

    hanmeimei.set_name("韩梅梅");
    // hanmeimei.set_age(28);
    hanmeimei.set_gender(false);

    lihua.walk();
    hanmeimei.say("请帮我给我的外国笔友Peter写封信");

    cout << lihua.get_age() << endl; // 读数据
    lihua.grow();
    cout << lihua.get_age() << endl; // 读数据

    return 0;
}