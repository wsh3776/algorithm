/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
//  */
// typedef pair<int, int> PII;

// bool cmp(PII a, PII b) {
//     return a.first < b.first;
// }

//哈希表查找复杂度为O(1)
// count函数比find简单
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {fsdf
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++ )
        {
            if (hash.count(target - nums[i])) return {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
        
//         // record the old indices
//         vector <pair <int, int>> v(n);
//         for (int i = 0; i < n; i ++) {
//             v[i] = {nums[i], i};
//         } 
        
//         sort(v.begin(), v.end(), cmp);
        
//         for (int i = 0; i < n; i ++) {
//             for (int j = i + 1; j < n; j ++) {
//                 if (v[i].first + v[j].first == target) return {v[i].second, v[j].second};
//                 if (v[i].first + v[j].first > target) break;
//             }
//         }
//         return {0, 1};
//     }
// };
 