/* ===== 解题思路 =====
1. 利用二进制去做
2. 1 <= x <= 2^m - 1
3. 二进制中第 i 位是 1，表示选了这个 pi
*/

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 20;

int p[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> p[i];

    LL res = 1;
    for (int i = 0; i < 1 << m; i ++) {
        for (int j = 0; j < m; j++) {
            LL t = 1;
            if (i >> k & j) {
                sign *= -1;
                if (t * p[j] < n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        }
        res += sign * n / t;
    }

    cout << res << endl;

    return 0;
}