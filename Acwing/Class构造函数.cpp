//Q:class私有成员如果没有在公有成员中设置set函数，那怎么初始化?

/*
一个构造函数是一个特殊种类的函数，它可以执行任何动作，但它的设计目的是用来执行初始化动作
*/

//作为一个类成员，数据域不能在声明时进行初始化

#include <iostream>

using namespace std;

//例如
class Circle {
public:
    double radius;  // double radius = 2.0 wrong

    // 构造函数——初始化
    Circle() {
        radius = 1;
    }

    Circle(double newRadius) {
        radius = newRadius;
    }

    double getArea() {
        return radius * radius * 3.14159;
    }
}; // Must place a semicolon here

/*
通过调用构造函数来创建对象,它是特殊的函数
1.构造函数的名字必须与类名相同
2.构造函数没有返回类型，连void也不可以
3.在创建对象时，构造函数被调用，它的作用就是初始化
4.写在public内
*/

// 在我们添加了构造函数后，编译器就不再提供此前默认的空构造函数Human() {}
class Human {
public:  // 公有的
    Human() {
        age_ = 15;
        gender_ = false;
    }

    Human(int age, bool gender) {  // 重载
        age_ = age;
        gender_ = gender;
    }

    // 推荐使用初始化列表法
    // // 初始化列表法 和上面的是等价的,唯一区别是可以给const变量赋值
    // Human(int age, bool gender)
    //  :age_(age), gender_(gender) {
    //      // 也可以写赋值
    //  }

    void walk() {  // 成员函数
        cout << name_ << " is walking..." << endl;
    }

    void say(string content) {
        cout << name_ << " says" << content << endl;
    }

    // Get/Set函数
    string get_name() const { // 说明这个函数是只读的
        return name_;
    }

    void set_name(string name) {
        name_ = name;
    }

    const int get_age() const {  //年龄设为只读，不能被更改
        return age_;
    }

    void grow() {
        age_ ++;
    }
    bool get_gender() const {  // 提高可读性
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
    Human lihua(25, true), hanmeimei(30, false); // 有两个重载的函数

    // age是只读变量，只要初始化时可以改变它的值
    lihua.set_name("李华");  // set 写数据
    lihua.set_gender(true);

    hanmeimei.set_name("韩梅梅");
    cout << hanmeimei.get_name() << (hanmeimei.get_gender() ? "(男)" : "(女)") << "的年龄是" << hanmeimei.get_age() << endl;

    lihua.walk();
    hanmeimei.say("请帮我给我的外国笔友Peter写封信");

    cout << lihua.get_age() << endl; // 读数据
    lihua.grow();
    cout << lihua.get_age() << endl; // 读数据

    return 0;
}