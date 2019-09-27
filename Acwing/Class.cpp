// 链接：https://www.bilibili.com/video/av45210655
#include <iostream> 

using namespace std;

/*
人类
	属性
		名字
		年龄大小
		性别
	能力
		走路
		说话
		...
*/

// leetcode也是用class Solution的
// class对象(属性+行为), class定义时必须加个分号，而函数则不用
// 把现实当中的一个物体一个事物抽象到我们的程序当中
class Human
{
public:  // 公有的

	void walk() {  // 成员函数
		cout << name_ << " is walking..." << endl;
	}

	void say(string content) {
		cout << name_ << " says" << content << endl;
	}

	// Get/Set函数
	string get_name() {
		return name_;
	}

	void set_name(string name) {
		name_ = name;
	}

	int get_age() {  //年龄设为只读，不能被更改
		return age_;
	}

	void set_age(int age) {
		age_ = age;
	}	

	void grow() {
		age_ ++;
	}
	bool get_gender() {
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
	Human lihua, hanmeimei;

	lihua.set_name("李华");  // set 写数据
	lihua.set_age(30);
	lihua.set_gender(true);

	hanmeimei.set_name("韩梅梅");
	hanmeimei.set_age(28);
	hanmeimei.set_gender(false);  

	lihua.walk();
	hanmeimei.say("请帮我给我的外国笔友Peter写封信");

	cout << lihua.get_age() << endl; // 读数据
	lihua.grow();
	cout << lihua.get_age() << endl; // 读数据

	return 0;
}