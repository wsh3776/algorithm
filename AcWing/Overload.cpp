// 重载：同一件事情可能因为场景不同，我们需要有不同的处理方式,比如2维求距离和3维求距离

/* 函数重载:相同名字，不同参数的函数  注意:函数重载只看参数个数和类型
	
	C++允许我们对函数进行重载。用不同的参数来区分重载的函数。编译器会判断我们传入的参数来寻找正确的函数，这个过程叫重载决策
	利用函数重载我们可以写适应不同输入的函数，简化我们的函数的调用过程
	重载不需要特别的形式说明。 只需要写两个名字相同，参数不同的函数即可
*/

/* 运算符重载
	很多时候我们需要我们自己定义的类也能够支持运算符的操作

	类外定义重载操作符的方法如下:
	返回类型 operator操作符(参数表) {
		...
		return 返回类型
	}

	参数表可以是类Human，可以是int, string等等
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

// 函数重载
double add(int a, int b)
{
    return a + b;
}

double add(int a, string s)
{
    int n = s.size();
    return a * n;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

// 函数重载只看参数个数和类型，不看返回值
// 但不能出现只是返回值不同的重载。
// 如
// int biggest(int a,int b);
// {
// 	...
// }
// float biggest(int a,int b)
// {
// 	...
// }

class Human
{
public:
    Human()
    {
    }

    Human(int age)
        : age_(age)
    {
    }

    // Get/Set函数
    int get_age()
    {
        return age_;
    }

    void set_age(int age)
    {
        age_ = age;
    }

private:
    string name_;
    int age_;
};

// 运算符重载
const int operator-(Human A, Human B)
{
    return A.get_age() - B.get_age();
}

Human operator&(Human A, Human B)
{
    return Human(A.get_age() + B.get_age()); // 要有对应的构造函数
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif

    // 调用方法 对象名.成员名
    Human lihua(30), hanmeimei(28);

    // Human temp = lihua & hanmeimei 也可以暂存返回值
    cout << "父母年龄和(add函数重载1): " << add(lihua.get_age(), hanmeimei.get_age()) << endl;
    cout << "父母年龄和(运算符重载&): " << (lihua & hanmeimei).get_age() << endl;
    int a = lihua - hanmeimei; //
    a++;
    cout << "父母年龄差(运算符重载-): " << lihua - hanmeimei << endl;
    cout << endl;

    cout << "add函数重载2: " << add(4, "we") << endl;
    cout << "add函数重载3: " << add(1, 2, 3) << endl;

    return 0;
}
