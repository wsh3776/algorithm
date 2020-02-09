/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月31日 星期二 18:15:47
 *    @Filename: 1260.二维网格迁移.cpp
 */

// Transfer Two dimensional matrix to one dimensional matrix
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        if (!grid.size() || !grid[0].size()) return {};
        // One dimensional matrix
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(grid);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t = i * m + j;
                k  = k % (m * n); 
                t = (t - k + m * n) % (m * n); // take the remainder
                ans[i][j] = grid[t / m][t % m];
                
            }
        }

        return ans;

    }
};



class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {

        // brute force
        while(k --) {
            vector<vector<int>> tmp(grid);

            int n = grid.size(), m = grid[0].size();

            for (int i = 0; i < n; i ++) {
                for (int j = 1; j < m; j ++) {
                    tmp[i][j] = grid[i][j - 1]
                }
            }

            for (int j = 1; j < m; j ++) {
                tmp[0][j] = grid[n - 1][j - 1]
            }

            tmp[0][0] = grid[n - 1][m - 1];

            grid = tmp;
        }

        return grid;

    }
};
