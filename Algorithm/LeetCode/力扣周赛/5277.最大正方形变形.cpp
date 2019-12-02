// 2019年12月1日 星期日
// 算法：
// 先设计求最大子矩阵边长的方法
//     1.f[i][j]表示以i和j为右下角的最大正方形的边长
//     2.如果a[i][j] = 0, 则f[i][j] = 0;
//     3.如果a[i][j] = 1, 则f[i][j] 是f[i][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1] + 1这三个的最小值
// 然后此题的正方形总数 = 每个位置最大正方形的边长之和

// 19年12月1日
class Solution {
public:
    int f[305][305];

    int countSquares(vector<vector<int>> &matrix) {
        memset(f, 0, sizeof(f));
        if (!matrix.size() || matrix[0].size()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + 1);
                    res += f[i][j];
                }
            }
        }

        return res;

    }
};



// LeetCode211题求最大正方形 19.3.31 以前写的垃圾代码

// 19年3月31日
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        if (matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else  {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    }
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                    }
                }
            }
        }
        return ans * ans;
    }
};