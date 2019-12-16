/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月16日 星期一 22:41:13
 *    @Filename: 1254.封闭岛屿的周长.cpp
 */


// 原题是求数量，我改成了求周长
const int N = 120;
typedef pair<int, int> PII;
#define x first
#define y second
PII q[N * N];
bool st[N][N];

int bfs(int sx, int sy, vector<vector<int>> &grid) {
    int flag = 1;
    int n = grid.size(), m = grid[0].size();
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    int cnt = 0;
    while(hh <= tt) {
        auto t = q[hh ++];
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (grid[a][b] == 1) cnt ++; // 统计周长
            else if (!st[a][b]) {
                // 处理周围
                if (a == 0 || a == n - 1 || b == 0 || b == m - 1) {
                    flag = 0;
                }

                q[++ tt] = {a, b};
                st[a][b] = true;
            }
        }
    }

    if (flag = 0) return 0;
    return cnt;
}

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        memset(st, 0, sizeof st);

        int res = 0;
        for (int i = 1; i < n - 1; i ++) { // 注意不要把边界枚举进去
            for (int j = 1; j < m - 1; j ++) {
                if (grid[i][j] == 1 || st[i][j]) continue;

                res += bfs(i, j, grid);
            }
        }
        return res;
    }
};