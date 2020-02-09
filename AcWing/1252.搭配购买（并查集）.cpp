/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月20日 星期五 15:21:04
 *    @Filename: 1252.搭配购买（并查集）.cpp
 */

#include <iostream>

using namespace std;

const int N = 10005;

int n, m, vol;
int p[N];
int a, b;

int main() {
    cin >> n >> m >> vol;
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }

    for (int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }

    // 计算每个连通块的v和w 最终一定连通块的祖宗一定满足p[x] == x
    for (int i = 1; i <= m; i ++) {
        cin >> a >> b;
        int pa = find(a), pb = find(b);

        if (pa != pb) {
            v[pb] += v[pa]; // 累计每个祖宗结点的值
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }

    // 01背包模版
    for (int i = 1; i <= n; i ++) {
        for (int j = vol; j >= v[i]; j --) {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }

    cout << f[vol] << endl;

    return 0;
}