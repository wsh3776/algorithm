// 状态表示：$f[i][j]$ 表示只从前 i 个物品中选（每个物品只能选一个），且恰好能拼成 j 的选法 （属性：个数）
// 状态计算：$f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]]$ （不一定都存在）
// 边界设置：画一个$(i,j)$框，看哪些变量要初始化，才能使循环中的每个变量都能被计算
// 问题答案：$f[n][m]$ 

#include <iostream>

using namespace std;

const int N = 110, M = 1e4 + 7;

int v[N];
int f[N][M];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) cin >> v[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            f[i][j] += f[i - 1][j];
            if (j >= v[i]) f[i][j] += f[i - 1][j - v[i]];
        }
    }

    cout << f[n][m] << endl;

    return 0;
}