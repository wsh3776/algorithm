// 3349. 膜两下将会让你送命
#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 998244353;

const int N = 1e6;

int primes[N], cnt;
LL euler[N];
bool st[N];

void getPrimes(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            euler[primes[j] * i] = (primes[j] - 1) * euler[i];
        }
    }
}

int main() {
    LL n, k;
    cin >> n >> k;

    getPrimes(N);
    // cout << euler[5] << endl;

    LL res = 0;
    for (int i = k; i <= n - k; i++) {
        res = (res % mod + n / i * euler[i] % mod) % mod;
    }
    cout << res << endl;

    return 0;
}
