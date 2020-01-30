
//2020年1月27日 星期一 21:09:41

// 分析：以三个数中最左边的为基准，做第一层循环，然后令0-这个数 = sum,就变成了two_sum题（双指针)
// |-3| -3 -3 1 1 2 2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int last = nums[0] - 1;
        for (int k = 0; k < n - 2; k ++) {
            while ((k < n - 2) && (last == nums[k])) k ++;
            if (k == n - 2) break;

            int sum = 0 - nums[k];

            // two_sum
            for(int i = k + 1, j = n - 1; i < j; ) {
                while(i < j && nums[i] + nums[j] > sum) j --;
                if (i == j) break;
                if (i < j && nums[i] + nums[j] == sum) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    // 跳过重复值
                    int t = nums[i];
                    int flag = 0;
                    while(i < j && t == nums[i]) {
                        i ++;
                        flag = 1;
                    }
                    if (flag) i --; // 坑点
                    t = nums[j];
                    while(i < j && t == nums[j]) j --;
                    if (i == j) break;

                }
                i ++;
            }
            last = nums[k]; // 更新last
        }

        return res;
    }
};

// 以中间的数为基准，这个方法不好，不能处理重复的情况
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 有序

        vector<vector<int>> res;
        // -3 -3 -3 1 1 2 2 防止中间重复遍历
        int last = nums[0] - 1;
        for (int k = 1; k < n - 1; k ++) { // 中间元素作为第一层遍历，避免重复
            if (nums[k] == last) continue;
            int sum = 0 - nums[k];

            // two-sum
            for(int i = 0, j = n - 1; i < k && k < j;) {
                while(k < j && nums[i] + nums[j] > sum) j --;
                if (k == j) break;
                if (nums[i] + nums[j] == sum) {
                    res.push_back({nums[i], nums[k], nums[j]});
                    // -3 -3 -3 1 1 2 2
                    int t = nums[i];
                    while(i < k && nums[i] == t) i ++;
                    t = nums[j];
                    while(k < j && nums[j] == t) j --;
                    if (i == k || j == k) break;
                }
                i ++;
            }
            last = nums[k];
        }

        return res;
    }
};