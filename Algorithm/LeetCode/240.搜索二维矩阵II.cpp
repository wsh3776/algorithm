// 同剑指offer 二维数组查找
// 从左到右递增，从上到下递增
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 单调性扫描O(n + m)
        if (!matrix.size() || !matrix[0].size()) return false;
        int n = matrix.size(), m = matrix[0].size();

        int i =0, j = m - 1;
        while(i < n && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j --;
            else i ++;
        }

        return false;
    }
};