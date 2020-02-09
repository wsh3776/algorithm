/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月12日 星期日 19:26:27
 *    @Filename: 3.最长不重复子串.cpp
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i ++) {
            hash[s[i]] ++;
            while(hash[s[i]] > 1) {
                hash[s[j]] --;
                j ++;
            }

            res = max(res, i - j + 1);
        }

        return res;

    }
};