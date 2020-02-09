/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月9日 星期四 15:46:47
 *    @Filename: 1269B.ModuloEquation.cpp
 */

// n = 2000
// 算法（枚举）：b[0]一定是从某个a[i]得到的，所以枚举n中情况，取最小值即可
// 复杂度：O(n^2logn)
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010;
int a[N], b[N], c[N];

int d;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++){
        cin >> a[i];
        c[i] = a[i];
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int res = 1e9 + 7;
    
    sort(b, b + n);

    for (int i = 0; i < n; i ++) {
        // 枚举得到b[0]的所有可能

        // 每次要还原a数组
        for (int i = 0; i < n; i ++) {
            a[i] = c[i];
        }

        if (b[0] >= a[i]) d = b[0] - a[i];
        else d = b[0] + m - a[i];

        for (int k = 0; k < n; k ++) {
            a[k] = (a[k] + d) % m;
        }

        sort(a, a + n);
        

        int j;
        for (j = 0; j < n; j ++) {
            if (a[j] == b[j]) continue;
            else break;

        }

        if (j == n) {
            res = min(res, d);
        }
    }

    cout << res << endl;

    return 0;
}
