/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月9日 星期一 16:35:48
 *    @Filename: Kruskal算法求最小生成树.cpp
 */

/*  ====算法分析====
    Krusal算法 
    1. 将所有边按权重从小到大排序 O(mlogm) m为边数
    2. 枚举每条边a b 权重c
       if a和b不连通，将这条边加入到集合中  使用并查集 O(m)

    不需要用领接表或邻接矩阵来存边，开个结构体即可
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

// 结构体排序+定义<运算符
struct Edge {
    int a, b, w;

    bool operator< (const Edge &R) const {
        return w < R.w;
    }
}edges[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i ++) {
        int a, b ,w;
        cin >> a >> b >> w;
        edges[i] = {a, b ,w};
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++) p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a =find(a), b = find(b);
        if (a != b) {
            p[a] = b; // 连通a和b
            res += w;
            cnt ++;
        }
    }

    if (cnt < n - 1) puts("impossible");
    else cout << res << endl;

    return 0;
}







