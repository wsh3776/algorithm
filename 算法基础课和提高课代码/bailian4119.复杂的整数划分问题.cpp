#include <cstring>
#include <iostream>

using namespace std;

const int N = 100;

int f[N][N];

// N划分成K个正整数之和的划分数
// 状态表示：f[i][j]表示用i个物品（可重复），且恰好拼成j的方案数
// 状态计算：此题状态转移比较难，f[i][j - i]表示用i个物品（可重复）且每个物品都大于1（同时减1）
//          f[i - 1][j - 1]表示用i个物品（可重复）且至少有一个物品是1（减去这个1）
// 边界设置：只要设置f[0][0] = 1，则所有状态都能被算出来
void slv1(int n, int k) {
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] += f[i - 1][j - 1];
            if (j >= i) f[i][j] += f[i][j - i]; 
        }
    }
    cout << f[k][n] << endl;
}

// N划分成不同正整数之和的划分数（01背包）
// 状态表示：f[i][j]表示只用前i种物品（最多一次），恰好拼成j的方案数
// 状态计算：f[i - 1][j] + f[i - 1][j - i] （这两个集合不一定存在）
// 边界设置：只要设置f[0][0] = 1，则所有状态都能被算出来
void slv2(int n) {
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] += f[i - 1][j];
            if (j >= i) f[i][j] += f[i - 1][j - i];
        }
    }
    cout << f[n][n] << endl;
}

// N划分成若干奇正整数之和的划分数（完全背包）
// 状态表示：f[i][j]表示只用前i种物品（只选奇数），恰好拼成j的方案数
// 状态计算：f[i - 2][j] + f[i][j - i] （这两个集合不一定存在）
// 边界设置：只要设置f[1][0] = 1，则所有状态都能被算出来
void slv3(int n) {
    f[1][0] = 1; 
    int i;
    for (i = 1; i <= n; i += 2) {
        for (int j = 0; j <= n; j++) {
            if (i > 2) f[i][j] += f[i - 2][j];
            if (j >= i) f[i][j] += f[i][j - i];
        }
    }
    cout << f[i - 2][n] << endl; // 出循环前是 i - 2
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        memset(f, 0, sizeof f);
        slv1(n, k);

        memset(f, 0, sizeof f);
        slv2(n);

        memset(f, 0, sizeof f);
        slv3(n);
    }
    return 0;
}