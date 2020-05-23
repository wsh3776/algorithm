// (x, y) = p, p为质数，则等价于(x / p, y / p) = 1
// 范围 1/p <= x/p, y/p <= n/p   左边界向上取，右边界向下取

#include <iostream>

using namespace std;

const int N = 1e7 + 7;

int primes[N], cnt;
int phi[N];
int sum[N];
bool st[N];

void getEuler(int n) {
    for (int i = 2; i <= n; i++) {
        phi[1] = 1;
        if (!st[i]) {
            phi[i] = i - 1;
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
            phi[primes[j] * i] = (primes[j] - 1) * phi[i];
        }
    }

    sum[1] = phi[1];
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + phi[i];
}

int main() {
    int n;
    cin >> n;

    getEuler(N);

    int res = 0;
    for (int j = 0; j < cnt; j++) {
        res += (2 * sum[n / [primes[j]]] - 1);
    }
    cout << res << endl;
}