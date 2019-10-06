typedef pair<int, int> PII;
int d[110][110];
int bfs(int a, int b, vector<vector<int>> &g ) {
    int n = g.size(), m = g[0].size();
    queue<PII> q;
    memset(d, -1, sizeof d);
    d[a][b] = 0;                            //d[x][y] != -1 表示该点被搜索过了
    q.push({a, b});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int x = 0, y = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();


        for (int i = 0; i < 4; i ++ ) {
            x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + g[x][y];
                q.push({x, y});
            }
            if (x >= 0 && x < n && y >= 0 && y < m) x = t.first, y = t.second;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (d[i][j] != 0)
                res = max(res, d[i][j]);
        }
        return res;
    }

    class Solution {
    public:
        int getMaximumGold(vector<vector<int>> &g) {
            int n = g.size(), m = g[0].size();

            int res = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    if (g[i][j] != 0)
                        res = max(res, bfs(i, j, g));
                }
            }


            return res;
        }
    };