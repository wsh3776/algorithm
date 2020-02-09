class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	int n = s.size();
    	vector <bool> dp(n + 1, false);
    	// leetcode leet code
    	unordered_set <string> hash(wordDict.begin(), wordDict.end());

    	// It will be clear when you calculate it on the draft paper
    	dp[0] = true;
    	for (int i = 1; i <= n; i ++) {
    		for (int j = 0; j < i; j ++) {
    			if (hash.find(s.substr(j, i - j)) != hash.end() && dp[j] == true) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}

    	return dp[n];
    }
};