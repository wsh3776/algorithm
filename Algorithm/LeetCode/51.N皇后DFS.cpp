class Solution {
public:
    static const int N = 30;
    char g[N][N];
    bool col[N], dg[N], udg[N];
   
    vector<vector<string>> ans;

    void dfs(int u, int n) {
        if (u == n) {
            vector<string> sol;
            for(int i = 1; i <= n; i ++) {
                string tmp = "";
                for (int j = 1; j <= n; j ++) {
                    tmp += g[i][j];
                }
                sol.push_back(tmp);
            }
            ans.push_back(sol);
            return;
        }

        for (int i = 1; i <= n; i ++) {
            if (!col[i] && !dg[u + i - 1] && !udg[u - i + n]) {
                g[u + 1][i] = 'Q';                               // 从u = 1开始填
                col[i] = dg[u + i - 1] = udg[u - i + n] = true;
                dfs(u + 1, n);
                g[u + 1][i] = '.';                               // 恢复现场，这步必须有，因为这题不像排列数字那题都能被覆盖到
                col[i] = dg[u + i - 1] = udg[u - i + n] = false; // 恢复现场，不影响下一个分支的搜索，这步很关键
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n ; j ++) {
                g[i][j] = '.';
            }
        }
        dfs(0, n);
        return ans;
    }
};