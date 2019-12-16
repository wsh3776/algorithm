/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月15日 星期日 09:17:55
 *    @Filename: 930.Binary Subarrays With Sum.cpp
 */

/*  ====算法分析====
    前缀和 时间复杂度:O(n), 空间复杂度:O(n)
    法一：利用map，让复杂度降低
    法二：用数组模拟map即可
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        unordered_map <int, int> hash;
        int sum[n + 1];
        sum[0] = 0;
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i - 1] + A[i - 1];
        }
        
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            hash[sum[i - 1]] ++;
            res += hash[sum[i] - S];
        }
        
        return res;
    }
};

// 数组模拟map，效率会快一些 78.63%
// 缺点是f数组的下标必须是正的，如果S是负数的话，最好还是用map
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        int sum[n + 1], f[n + 1];
        memset(f, 0, sizeof f);
        sum[0] = 0, f[0] = 0;
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i - 1] + A[i - 1];
        }
        
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            f[sum[i - 1]] ++;
            if(sum[i] - S >= 0) res += f[sum[i] - S];
        }
        
        return res;
    }
};