/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int> &nums) {
        // 每次更新最大距离，然后把每一步所能跳的范围作为一个区间，每当i ==
        // end时，则必须要跳一步，如果end大于等于size - 1，则可退出for循环
        int steps = 0;
        int end = 0;
        int maxPosition = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxPosition = max(maxPosition, i + nums[i]);
            if (i == end) {
                end = maxPosition;
                steps++;
                if (end >= nums.size() - 1) break;
            }
        }

        return steps;
    }
};
// @lc code=end
