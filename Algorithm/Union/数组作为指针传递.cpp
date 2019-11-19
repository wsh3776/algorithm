*(a+n) <=> a[n]; // a为数组名
 // 数组名作为函数参数传递后，其大小信息丢失，只剩下指向数组中第一个元素的信息，这也是为什么如果在接受数组参数的函数中访问数组的各个元素，需在定义数组的域范围将数组大小作为另一辅助参数传递
// C++实际上是将数组作为指针来传递，而该指针指向数组的第一个元素。至于后面数组在哪里结束，C++的函数传递机制并不负责

//  test(a); // 在调用时数组只要写函数名即可

// 二维数组的第二个括号内的参数必须写
void f(int x[][5]) {
  ...;
}

int a [10][5];
f(a); // 调用数组时也是直接写函数名

#include <iostream>
 
using namespace std;
 
// C++中数组作为函数参数是传址
void test(int *a) // int a[]; 等价于 int *a;
{
  cout << endl;
 
  cout << "in func..." << endl;
  cout << "array address: " << a << endl; // 0x7fff2bc25750

  // 数组名作为函数参数传递后，其大小信息丢失，只剩下指向数组中第一个元素的信息
  cout << "array size: " << sizeof(a) << endl; // 8，因为地址的大小是8
  cout << "array element count: " << sizeof(a) / sizeof(a[0]) << endl; // sizeof(a[0])的大小是4，第一个是int还是知道的
 
  cout << "changing the 3th element's value to 10." << endl;
  
  *(a + 2) = 10;
  // a[2] = 10;
}
 
int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int *b = a; // 新定义的指针的大小是8
  cout << "point b size: " << sizeof(b) << endl << endl;
  cout << "in main..." << endl;
  cout << "array address: " << a << endl; // 0x7fff2bc25750
  cout << "array size: " << sizeof(a) << endl;  // 20
  cout << "array element count: " << sizeof(a) / sizeof(a[0]) << endl; // 5
 
  test(a); // 在调用时数组只要写函数名即可
 
  cout << endl << "the 3th element's value: " << a[2] << endl;
 
  return 0;
}

