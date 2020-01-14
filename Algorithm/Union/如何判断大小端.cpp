#include <iostream>
#include <cstring>

using namespace std;

// 0x  12      34
//     高字节   低字节

//     低地址   高地址  大端模式
//     高地址   低地址  小端模式

void IsBigEndian() { // 原理：联合体union的存放顺序是所有成员都从低地址开始存放，而且所有成员共享存储空间
    union temp {
        short a; // 2个字节
        char b;
    } temp;

    temp.a = 0x1234;
    if( temp.b == 0x12 ) { // 低字节存的是数据的高字节数据
        cout << "大端模式" << endl;
    } else {
        cout << "小端模式" << endl;
    }
}

int main() {
    IsBigEndian();

    return 0;
}
