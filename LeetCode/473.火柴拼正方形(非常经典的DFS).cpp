// 2020年1月14日 星期二 13:38:54
class Solution {
public:
    int n, sum, qt;
    bool makesquare(vector<int> &nums) {
        n = nums.size();
        if (n == 0) return false;
        for (auto x : nums) sum += x;
        if (sum % 4 != 0) return false;
        qt = sum / 4;

        return dfs(0, 0, 0, 0, 0, nums);
    }

    bool dfs(int u, int x, int y, int z, int s, vector<int> &nums) {
        if (x == qt && y == qt && z == qt && s == qt) return true;
        if (u == n) return false;


        // 枚举for(int i = 0; i < 4; i ++) 4个分支
        if (x + nums[u] <= qt && dfs(u + 1, x + nums[u], y, z, s, nums)) return true;
        if (y + nums[u] <= qt && dfs(u + 1, x, y + nums[u], z, s, nums)) return true;
        if (z + nums[u] <= qt && dfs(u + 1, x, y, z + nums[u], s, nums)) return true;
        if (s + nums[u] <= qt && dfs(u + 1, x, y, z, s + nums[u], nums)) return true;

        return false;
    }
};
