class Solution {
public:
    // 此算法：直接用坐标公式
    // 也可以先做个转置，然后依次变换一下每一行的元素即可
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i ++) { // 从外层到内层
            for (int j = i; j < n - 1 - i; j ++) { // 循环一圈                 
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
        return;
    }
};