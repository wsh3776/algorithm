/*
 * @Date: 2020-05-17 09:34:48
 * @FilePath: /Wilson79/Algorithm/OJ/POJ3233矩阵快速幂.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-17 10:21:27
 */

#include <iostream>

using namespace std;

const int N = 50;
int n, k, mod;

// 定义结构体
struct mat {
    int m[N][N];
    mat () {
        memset(m, 0, sizeof m);
        for (int i = 0; i < N; i ++) {
            m[i][i] = 1;
        }
    }
};

// 矩阵乘法
mat multi(mat a, mat b) {
    mat res;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++ ) {
            res.m[i][j] = 0;
            for (int k = 0; k < n; k ++) {
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
            }
        }
    }
    return res;
}

// 矩阵相加
mat add(mat a, mat b) {
    mat res;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            res.m[i][j] = (a.m[i][j] + b.m[i][j]) % mod;
        }
    }
    return res;
}

// 矩阵快速幂
mat fastpow(mat a, int k) {
    mat res;
    while (k) {
        if (k & 1) res = multi(res, a);
        a = multi(a, a);
        k >>= 1;
    }
    return res;
}

// 矩阵求和
// sum(k) = (E+A^{k/2}) * sum(k/2); // 偶数
// sum(k) = (E+A^{k-1}/2) * sum((k - 1)/2) + A^k; // 奇数
mat sum(mat a, int k) {
    mat tmp;
    if (k == 1) return a;
    if (k & 1) {
        mat t = multi(sum(a, (k-1)/2),add(tmp, fastpow(a, (k-1) / 2)));
        return add(t, fastpow(a, k));
    } else {
        return multi(sum(a, k/2),add(tmp, fastpow(a, k / 2)));
    }
}

int main() {
    cin >> n >> k >> mod;

    // 读矩阵
    mat a; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> a.m[i][j];
        }
    }

    mat res = sum(a, k);

    // 输出矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cout << res.m[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}