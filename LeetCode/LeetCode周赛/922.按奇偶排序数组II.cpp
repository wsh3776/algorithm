/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月6日 星期五 13:30:30
 *    @Filename: 922.按奇偶排序数组II.cpp
 */

/*  ====算法分析====
    双指针 时间复杂度:O(n), 空间复杂度:O(1)
    1.把偶数放在对应的位置后，奇数自然就成立
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        for (int i = 0, j = 1; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while(A[j] % 2 == 1) { // 找到奇数为上的偶数为止
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;    
    }
};
