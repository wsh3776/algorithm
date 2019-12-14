/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月8日 星期日 11:02:26
 *    @Filename: 使结果不超过阈值的最小除数.cpp
 */

// 教训：
// 1.这题一开始没看清楚题目，害我浪费了很多时间
// 2.先把朴素算法写出来，这样会慢慢有优化的灵感
// 3.向上取整时要注意先乘以1.0
// 算法：二分

class Solution {
public:
    static bool check(int t, vector <int> nums, int threshold) {
        int sum = 0;
        for (int j = 0; j < nums.size(); j ++) {
            sum += ceil(1.0 * nums[j] / t); // 向上取整时要注意先乘以1.0
        }
        if (sum <= threshold) return true;
        return false;
    }


    int smallestDivisor(vector<int> &nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = nums[n - 1];
        while(l < r) {
            int mid = l + r >> 1;
            if (check(mid, nums, threshold)) r = mid;
            else l = mid + 1;
            //cout << mid << endl;
        }

        return l;
    }
};

