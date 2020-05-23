/*
 * @Date: 2020-05-16 12:53:29
 * @FilePath: /Wilson79/Algorithm/OJ/POJ3070Fibonacci.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-16 13:00:02
 */
#include <iostream>

using namespace std;

const int N = 100, mod = 1e4;
int n, k;

struct mat {
    int m[N][N];
    mat() { // 用构造函数初始化成 单位矩阵E
        memset(m, 0, sizeof m);
        for (int i = 0; i < N; i++)
            m[i][i] = 1;
    }
};

// 矩阵乘法
mat multi(mat a, mat b) { 
    mat c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j]; // 累加
            }
            c.m[i][j] %= mod;
        }
    }
    return c;
}

// 矩阵快速幂（核心）
mat fastpow(mat a, int k) { 
    mat res;
    while (k) {
        if (k & 1) res = multi(res, a);
        a = multi(a, a);
        k >>= 1;
    }
    return res;
}

int main() {
    n = 2;
    mat a, res;
    // 输入矩阵
    a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
    a.m[1][1] = 0;
    
    while (cin >> k && k != -1) {
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        res = fastpow(a, k - 1);
        cout << (res.m[1][0] * 1 + res.m[1][1] * 1) % mod << endl;
    }
}