/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月6日 星期五 19:36:36
 *    @Filename: 朴素Dijkstra算法.cpp
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510; // 稠密图 用邻接矩阵来存储

int n, m;
int g[N][N]; // 邻接矩阵
int dist[N]; // 从1号点到每个点当前的最短距离
bool st[N];  // 表示每个点的最短路是不是已经确定了
int path[N]; // 记录路径

int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i ++) {  // 循环n次
        int t = -1; // t的作用是找到未确定距离中最小的点
        for (int j = 1; j <= n; j ++) { // 最开始得到的是dist[1]=0
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j; // 如果dist[t] = dist[j] 仍选t就行了
        }

        st[t] = true; // 找到了距离最小的一个点

        // 用t去更新下其他的点 第一轮确定了各个顶点到1号点的直接距离
        for (int j = 1; j <= n; j ++) {
            if(dist[t] + g[t][j] < dist[j]) {
                dist[j] = dist[t] + g[t][j];
                path[j] = t;
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1; // 不存在1号点到n号点的路径
    
    return dist[n]; // 返回1号点到n号点的最短路径
}

void printPath(int i) { // 逆序输出第i个点的最短路径
    int k = i;
    cout << k << " ";
    while(k != 1) {
        cout << path[k] << " ";
        k = path[k];
    }
}

// 重边和自环，只需保留最短的一条边就像了
int main() {
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof(g));

    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;  // 有向图
        g[a][b] = min(g[a][b], c); // 重边只需保留长度最小的一条

    }

    int t = dijkstra();
    cout << t << endl;
    
    printPath(n); 

    return 0;
}


