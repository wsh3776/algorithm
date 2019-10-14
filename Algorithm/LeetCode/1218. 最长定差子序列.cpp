// map可以当做数组，因此用普通数组也可以，只不过要加个偏移
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map <int, int> dp;
        dp.clear();
        
        // dp[v]表示以v结尾的同时以difference为公差的最长定差子序列 
        int n = arr.size(), res = -1e9;
        for(int i = 0; i < n; i ++) {
            dp[arr[i]] = max(dp[arr[i]], dp[arr[i] - difference] + 1);
            res = max(dp[arr[i]], res);
        }
        
        return res;
    }
};

