/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size(), maxPosition = 0;
        for (int i = 0; i < n; i++) {
            if (maxPosition < i) return false;
            maxPosition = max(maxPosition, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
