// sort函数其实就是一个函数模板,并且调用时省略了<类型>  
// C++reference的函数大部分采用了模板形式
// template <typename T> 或 template <class T> 一般没什么区别

// 不同的参数虽然可以用多个重载的函数来实现，但未免太麻烦，如果有50种参数，就需要引入temple模板来简化代码
/*
int add(int x, int y) {
	return x + y;
}

double add(double x, double y) {
	return x + y;
}

Coor2D add(Coor2D x, Coor2D y) {  // 自己编写的类需要重载加法运算符
	return x + y;
}

...
*/

/* 普通函数与模板函数的区别:
(1) 普通函数:参数值未定，但参数类型确定
(2) 函数模板:参数值未定，而且参数类型未定
*/
// temple模板
// 我们编写一个模板->在编译的时候自动生成它在某个类型下的版本——简单地讲我们把重载的过程交给了编译器去做

#include <bits/stdc++.h>

using namespace std;

template<typename T> // 参数表  typename是说明T是某个类型  T模板参数类型
T add(T x, T y) {
    return x + y;
}

template<class T>
void append_num(T *arr, int size) { // 数组添加一个元素
    T items[size + 1];
    for (int i = 0; i < size; i ++) {
        items[i] = arr[i];
    }

    items[size] = items[size - 2] + items[size - 1];
    for (int i = 0; i < size + 1; i ++) {
        cout << items[i] << endl;
    }
}


int main() {
	// <>是用来告诉编译器你输入的参数是哪个类型的，进而生成对应的函数模板
	// 比如<string> 告诉编译器T *arr 应该是string *arr
    string s[] = {"1", "1", "2", "3", "5"};
    append_num<string>(s, 5);

    cout << "______" << endl;

    int nums[] = {1, 1, 24, 3, 5};
    sort<int*>(nums, nums + 5);  // 通常<int*>省略，因为你自己不好判断
    append_num<int>(nums, 5);

    cout << "______" << endl;

    // 通过模板生成函数的过程，称为实例化
    cout << add<double>(1.5, 2.2) << endl;   // 把模板中的T全部换成double
    cout << add<int>(1, 2) << endl;      // 这两个其实是两个函数

    // 不加<类型>也行，因为编译器会根据你跟的参数类型自动判断是哪一种
    // 当然模板没有参数，但模板内部用到T时，一定要用<类型>声明



    return 0;
}
