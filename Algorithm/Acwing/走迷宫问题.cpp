// 迷宫路径 BFS + 输出最短路径
// g表示图 d表示距离
// d[0][0] = 0 表示取过这个位置了
// 用一个pr数组存前一个就行了， 路径
// BFS第一次搜到的才是最短距离， 不然第二次搜到就不是最短距离 就没必要去处理他了
// 把定义和执行语句分开写 
    
/* 
    这里我犯了个非常严重的错误，因为x变了，后面还用pre[x][y]就会出错
    while (x || y) {
        x = pre[x][y].first, y = pre[x][y].second;   
        cout << x << " " << y << endl; 
    }
*/
    
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];                       // 一般都设为全局变量, pre[N][N]用来存路径 因为每个点只来源于一个点
PII pre[N][N];                              // DFS不用这样存，每一条都直接输出，所以空间是0(n)


int bfs()
{
    queue<PII> q;
    memset(d, -1, sizeof d);
    d[0][0] = 0;                            // d[x][y] != -1 表示该点被搜索过了
    q.push({0, 0});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                pre[x][y] = {t.first, t.second};
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    
    // 逆序输出路径
    int x = n - 1, y = m - 1;
    while (x || y) {
        auto t = pre[x][y];   
        cout << x << " " << y << endl; 
        x = t.first, y = t.second;
    }
    cout << 0 << " " << 0 << endl;

    
    return d[n - 1][m - 1];
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;
    
    return 0;
}


