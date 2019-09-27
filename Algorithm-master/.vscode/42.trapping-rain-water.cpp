/*
 * @Author: shwei
 * @Date: 2019-08-23 19:52:16
 * @LastEditors: shwei
 * @LastEditTime: 2019-08-23 23:40:48
 */
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector <int> left(n), right(n);
        
        // get leftmax and rightmax
        left[0] = height[0];
        for (int i = 1; i < n; i ++) {
            left[i] = max(left[i - 1], height[i]);
        }
        
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --) {
            right[i] = max(right[i + 1], height[i]);
        }
        
        // traverse all bars
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += min(left[i], right[i]) - height[i];
        }
        
        return ans;
    }
};

