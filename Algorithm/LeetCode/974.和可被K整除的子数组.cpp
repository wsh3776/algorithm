/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月7日 星期六 23:42:00
 *    @Filename: 974.和可被K整除的子数组.cpp
 */

/*  ====算法分析====
    原理作差 
    1--->        余数是tot
    2----->      余数是tot
    ...

    m-------->   余数是tot

    (m - 已经有的tot) % K == 0;
    所以每次只要算已经有的tot数量即可
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map <int, int> hash;
        
        int tot = 0, res = 0;
        hash[0] = 1;
        for (int x : A) {
            tot = (tot + x % K + K) % K; // 处理x为负数的情况，保证tot是0~K-1
            res += hash[tot]; // 表示前面已经有的和tot同余的数量
            hash[tot] ++;
        }
        
        return res;
    }
};



