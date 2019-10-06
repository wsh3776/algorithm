#include <iostream>

using namespace std;

const int N = 1010;

int f[N], v[N], w[N];

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n ; i ++) {
        cin >> v[i] >> w[i]; // 简化代码   !!!其实可以直接用v和w简写
        for (int j = m; j >= v[i]; j --) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            // 朴素做法:
            // f[i][j] = f[i - 1][j];
            // if (j >= v[i])
            // f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            // f[i][j] 表示只从前i个物品中选择，总体积不超过j的最大价值
            // j倒过来遍历，是保证右边的f[..]没有被算过
        }
    }

    cout << f[m] << endl;

    return 0;
}
