class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {

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