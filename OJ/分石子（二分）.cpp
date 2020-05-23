/*
 * @Date: 2020-05-09 14:27:00
 * @FilePath: /Wilson79/Algorithm/OJ/分石子（二分）.cpp
 * @LastEditors: cs_shwei@163.com
 * @LastEditTime: 2020-05-09 14:46:26
 */
class Solution {
public:
    /**
     * 分石子
     * @param n int整型
     * @param m long长整型
     * @param a int整型vector
     * @return int整型
     */

    // 最小值最大化问题，二分出最后一个满足条件的数
    // 若当前最小值为 x = 3， 则10要分成3 3 4，因为要尽量用到分裂次数 m-n 次
    typedef long long LL;
    
    bool check(vector<int> &a, LL m, int x) {
        LL sum = 0;
        for (int i = 0; i < a.size(); i ++) {
            sum += a[i] / x; // 10/3 = 3堆
            if (a[i] < x) return false; // 容易忘记写这条件
        }
        return sum >= m;
    }

    int solve(int n, LL m, vector<int> &a) {
        LL l = 1, r = 1e18;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (check(a, m, mid))
                l = mid;
            else
                r = mid - 1;
        }
    
        return r;
    }
};