class Solution {
public:
    // 二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        
        int l = 0, r = n * m - 1;
        while ( l < r) {
            int mid = l + r >> 1; 
            if (matrix[mid / m][mid % m] < target) l = mid + 1;
            else r = mid;
        }
        // 这里找的是大于等于target的第一个数 例： [[1,1]] 2  
        // 如果数组元素都比target小，则l会不断加一，直到等于r，也就是到达一开始设定的右端点
        
        return matrix[l / m][l % m] == target;
    }
};