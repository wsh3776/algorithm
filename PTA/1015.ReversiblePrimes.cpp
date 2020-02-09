#include <iostream>
#include <cmath>

using namespace std;

// 判断素数函数
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}


int main() {
    int n, d;
    while(cin >> n) {
        if (n < 0) break;
        cin >> d;

        if (!isPrime(n)) {
            cout << "No" << endl;
            continue;
        }
        string s = "";
        while(n / d != 0) {
            s += to_string(n % d);
            n /= d;
        }
        s += to_string(n % d);

        // 注意字符数字和普通数字的转换
        int ns = s.size(), rsn = 0, digit = pow(d, ns - 1);
        for (int i = 0; i < ns; i ++) {
            rsn += (s[i] - 48) * digit;
            digit /= d;
        }

        if (isPrime(rsn)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }


    return 0;
}


