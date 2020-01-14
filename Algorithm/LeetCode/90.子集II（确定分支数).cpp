/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月14日 星期二 11:23:26
 *    @Filename: 90.子集II（确定分支数).cpp
 */

class Solution {
public:
    vector <vector<int>> res;
    vector <int> tmp;

    // 112223相同个数有k个，则有k + 1个分支
    void dfs(int u, vector<int> &nums) {
        int n = nums.size();
        if (u == n) {
            res.push_back(tmp);
            return;
        }

        // 确定当前分支数
        int tt = nums[u];
        int j = u;
        while(j < n && nums[u] == nums[j]) j++;
        int k = j - u;
        u = j;

        // k + 1个分支
        for (int ii = 0; ii <= k ; ii ++) {
            for (int t = 0; t < ii; t ++) {
                tmp.push_back(tt); // 加入ii个1
            }
            dfs(u, nums);
            for (int t = 0; t < ii; t ++) {
                tmp.pop_back();         // 恢复现场
            }
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        int n = nums.size();
        // 排序
        sort(nums.begin(), nums.end());

        dfs(0, nums);
        return res;
    }
};
