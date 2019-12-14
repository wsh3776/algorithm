/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月9日 星期一 10:42:51
 *    @Filename: 朴素prim算法.cpp
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1; // 每次找到集合外的距离这个集合最小的点，t == -1表示当前我们还没有找到任何一个点
        for (int j = 1; j <= n; j ++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j; // !st[j]表示在集合外的点
        
        if (i && dist[t] == INF) return INF; // 图不连通
        if (i) res += dist[t]; 
        
        st[t] = true; // 将t加到集合中
        
        // 用t去更新其他点到集合的距离 已排除自环负值更新出错的情况
        // 已经加到集合中的点的距离变化没有关系，因为不会加到res中
        for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]); // Dijkstra算法是dist[t] + g[t][j] 注意区别
    }

    return res;
}



int main() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    while(m --) {
        int a, b ,c;
        cin >> a >> b >> c;
        // 去自环+去重边+无向图
        if (a != b) g[a][b] = g[b][a] = min(g[a][b], c); 
    }

    int t = prim();
    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}