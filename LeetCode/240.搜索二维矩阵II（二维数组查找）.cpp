// 从左到右递增，从上到下递增
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // 单调性扫描O(n + m)
        if (!array.size() || !array[0].size()) return false;
        int n = array.size(), m = array[0].size();

        int i =0, j = m - 1;
        while(i < n && j >= 0) {
            if (array[i][j] == target) return true;
            if (array[i][j] > target) j --;
            else i ++;
        }

        return false;
    }
};




