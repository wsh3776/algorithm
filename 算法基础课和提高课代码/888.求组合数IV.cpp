/* ===== 解题思路 =====
1. 筛质数
2. 求出每个质数的次数
3. 高精度乘法 p1a1 * p2a2 * ... pkak
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 5007;

int primes[N], cnt;
bool st[N];

// 线性筛
void getPrimes(int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

// 求出 n! 中 p 的次数
int get(int n, int p) {
    int sum = 0;
    while (n) {
        sum += n / p;
        n /= p;
    }
    return sum;
}

// 大数乘法
vector <int> mul(vector<int> A, int b) {
    vector <int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 去前导零
    return C;
}

int main() {
    int a, b;
    cin >> a >> b;

    getPrimes(a);

    vector<int> res(1, 1);
    // 求每个质数的次数 + 大数乘法
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        int s = get(a, p) - get(a - b, p) - get(b, p);
        for (int j = 0; j < s; j++)
            res = mul(res, p);
    }

    for (int i = res.size() - 1; i >= 0; i --) cout << res[i];

    return 0;
}