/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月5日 下午08:06:03
 *    @Filename: 350.两个数组的交集II.cpp
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> hash;
        vector <int> res;
        for (int x : nums1) {
            hash[x] ++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            int t = nums2[i];
            if (hash[t] > 0) {
                res.push_back(t);
                hash[t] --;
            } 
        }
        return res;
    }
};