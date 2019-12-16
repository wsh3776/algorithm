/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月16日 星期一 11:45:20
 *    @Filename: 1219.黄金矿工.cpp
 */

// 此题未AC
// 这题我用宽搜，发现只能过26/42个样例，原来宽搜是不对的，因为这个路径可能是迂回型的，它求的是最大性，而宽搜是来保证最小性的，所以应该用深搜
const int N = 30;
typedef pair<int, int> PII;
#define x first
#define y second

PII q[N * N];
bool st[N][N];
int dist[N][N];

// 求的是“最小值”,而题目是求最大值，必须用dfs
int bfs(int sx, int sy, vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int hh = 0, tt = 0;
    int mx = 0;

    q[0] = {sx, sy};
    st[sx][sy] = true;
    dist[sx][sy] = grid[sx][sy]; // 第一个位置大小
    mx = max(mx, dist[sx][sy]);

    // cout << "T: " << sx << " " << sy << endl;
    
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while(hh <= tt) {
        auto t = q[hh ++];
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (grid[a][b] == 0 || st[a][b]) continue;
            
            dist[a][b] = dist[t.x][t.y] + grid[a][b];
            mx = max(mx, dist[a][b]);
            cout << "Here: " << a << " " << b << endl;
            q[++ tt] = {a, b}; 
            st[a][b] = true;
        }
    }
    return mx;
}


class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                memset(st, 0, sizeof st); 
                memset(dist, 0, sizeof dist); // 枚举不同起点，故每次都要初始化
                res = max(res, bfs(i, j, grid));
            }
        }

        return res;

    }
};