#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int & y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    } else {
        int d = exgcd(b, a % b, x, y); // 递归可认为已求出 b 和 a%b的对应系数
        int k = y, t = x - a / b * y;
        x = k, y = t;
        return d;
    }
}

int main() {
    int n;
    cin >> n;

    int a, b, x, y;
    while (n --) {
        cin >> a >> b;
        exgcd(a, b, x, y); // 传引用
        cout << x << " " << y << endl;
    }
    

    return 0;
}