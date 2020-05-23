/* ===== 解题思路 =====
1. 如果直接判断素数，时间复杂度为T * n * sqrt n
2. 我们可以通过线性筛预处理出primes质数数组和st标记数组
*/
#include <iostream>

using namespace std;

const int N = 1e6 + 7;

int primes[N], cnt;
bool st[N];

// 线性筛质数
void getPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    getPrimes(N); // 初始化是 N，不是 n

    int n;
    while (cin >> n, n) {
        int i;
        for (i = 0; primes[i] < n; i++) {
            int a = primes[i];
            int b = n - a;

            if (!st[b]) { 
                cout << n << " = " << a << " + " << b << endl;
                break;
            }
        }

        if (i == cnt) cout << "Goldbach's conjecture is wrong." << endl;
    }

    return 0;
}
