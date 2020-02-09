class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        int n = rods.size(), sum = 0;
        vector<vector<int>> f(n + 1, vector<int>(5010, -5010));

        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += rods[i - 1];
            for (int j = 0; j <= sum; j++) {
                f[i][j] = max(f[i][j], f[i - 1][j]);
                int x = rods[i - 1];
                if (j + x <= sum)
                    f[i][j + x] = max(f[i][j + x], f[i - 1][j]);
                if (x <= j)
                    f[i][j - x] = max(f[i][j - x], f[i - 1][j] + x);
                else
                    f[i][x - j] = max(f[i][x - j], f[i - 1][j] + j);
            }
        }
        return f[n][0];
    }
};
