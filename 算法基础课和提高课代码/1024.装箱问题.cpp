// 把物品的体积同时看做体积和价值，问题转化为在不超过背包最大容量的情况下，最大价值是多少

#include <iostream>

using namespace std;


const int N = 2e4 + 7;

int f[N][N];
int v[N], w[N];

int main () {
    int m, n;
    cin >> m >> n;

 
    for (int i = 1; i <= n; i ++) {
        int d;
        int d;
        cin >> d;
        v[i] = d, w[i] = d;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    cout << f[n][m] << endl;

    return 0;
}