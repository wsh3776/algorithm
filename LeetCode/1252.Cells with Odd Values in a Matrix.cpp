class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>> &indices) {
        int a[n][m];
        memset(a, 0, sizeof(a));

        // brute force
        for (auto t : indices) {
            int x = t[0], y = t[1];
            for (int i = 0; i < m; i ++) a[x][i] ++;
            for (int i = 0; i < n; i ++) a[i][y] ++;
        }

        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i][j] & 1) ans ++;
            }
        }

        return ans;
    }
};