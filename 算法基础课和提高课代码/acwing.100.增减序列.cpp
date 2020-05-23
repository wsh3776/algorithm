#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 7;

int a[N], b[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++)  cin >> a[i];

    for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];

    LL p = 0, q = 0;
    for (int i = 2; i <= n; i ++) {
        if (b[i] > 0) p += b[i];
        else q -= b[i];
    }

    cout << max(p, q) << endl; // 最小操作数

    cout << abs(p, q) + 1 << endl; // 可能的结果数

    return 0;
}













