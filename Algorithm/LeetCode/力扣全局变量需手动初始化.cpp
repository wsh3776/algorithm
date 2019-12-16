// 注意变量和定义函数的位置，全放class外面，但每次记得初始化全局变量
const int N = 1000;
typedef pair<int, int> PII;
PII q[N * N];
bool st[N][N]; // 需手动初始化

void bfs(int sx, int sy, vector<vector<char>> &grid) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while(hh <= tt) {
        PII t = q[hh ++];
        for (int i = 0; i < 4; i ++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size()) continue;
            if (grid[a][b] != '1' || st[a][b]) continue;

            q[++ tt] = {a, b};
            st[a][b] = true;
            //cout << a << ":" << b << endl;
        }
    }
    return;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        memset(st, 0, sizeof st); // 每次初始化全局变量

        int cnt = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1' && !st[i][j]) {
                    bfs(i, j, grid);
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};