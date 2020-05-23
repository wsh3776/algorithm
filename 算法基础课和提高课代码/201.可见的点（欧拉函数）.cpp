// 筛法求欧拉函数  2 * (phi[1] + phi[2] + ... + phi[n]) + 1
// 时间复杂度 O(NC)
#include <iostream>

using namespace std;

const int N = 1e3 + 7;
int primes[N], cnt;
int phi[N];
int sum[N];
bool st[N];

void getEuler(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
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
    for (int i = 2; i <= n; i ++) sum[i] = sum[i - 1] + phi[i];
}

int main() {
    int T;
    cin >> T;

    getEuler(1000);

    for (int i = 1; i <= T; i++) {
        int n;
        cin >> n;

        int res = 2 * sum[n] + 1;
        cout << i << " " << n << " " << res << endl;
    }

    return 0;
}