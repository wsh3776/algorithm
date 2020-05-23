/* ===== 解题思路 =====
1. 质数和合数会有连边，质数和质数不会有连边，合数和合数不会有连边，所以构成一个二分图
2. 当 n = 1 时，染色数为 1，当 n >= 2 时，染色数为 2
3. 线性筛质数，如果是质数则标记为 1，否则标记为 2
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int primes[N], cnt;
bool st[N];

void getPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt ++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;

    getPrimes(N); // 预处理出所有质数

    // 染色数
    if (n <= 2) cout << 1 << endl;
    else cout << 2 << endl;

    // 染色 
    for (int i = 2; i <= n + 1; i ++) {
        if (!st[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }

    return 0;
}