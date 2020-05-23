// 在番茄酱的帮助下完成
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 7;

int p;

LL fact[N], infact[N];

LL qmi(int a, int k, int p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// 预处理阶乘
void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < p; i++) {
        fact[i] = fact[i - 1] * i % p;
        infact[i] = infact[i - 1] * qmi(i, p - 2, p) % p;
    }
}

LL lucas(LL a, LL b) {
    if (a < b) return 0;
    if (a < p && b < p) return fact[a] * infact[a - b] % p * infact[b] % p;
    
    LL x = a % p, y = b % p;
    if (x < y) return 0;
    LL tmp = fact[x] * infact[x - y] % p * infact[y] % p;
    return tmp * lucas(a / p, b / p) % p; 
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        LL a, b;
        cin >> a >> b >> p;

        init(); // 先预处理阶乘
        cout << lucas(a, b) << endl;
    }
    
    return 0;
}

