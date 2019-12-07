/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月5日 下午07:58:04
 *    @Filename: 349.两个数组的交集.cpp
 */


/*  ====算法分析====
    set 时间复杂度:O(), 空间复杂度:O()
    1.先把nums1加到set里，set是集合，不重复
    2.遍历nums2，如果在set里能找到，则在答案里加上这个值，同时删去set中这个值
*/
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set <int> hash;
        vector<int> res;
        for (auto x : nums1) hash.insert(x);
        for (int i = 0; i < nums2.size(); ++i) {
            if (hash.find(nums2[i]) != hash.end()) {
                res.push_back(nums2[i]);
                hash.erase(nums2[i]);
            }
        }
        return res;
    }

};