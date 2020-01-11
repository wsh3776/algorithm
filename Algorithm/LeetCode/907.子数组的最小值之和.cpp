/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月19日 星期四 19:28:01
 *    @Filename: 907.子数组的最小值之和.cpp
 */

const int N = 30010;
const int mod = 1e9 + 7;
int stk[N];
int Left[N];
int Right[N];
int tt;
class Solution {
public:
    int sumSubarrayMins(vector<int> &A) {
        int n = A.size();
        tt = 0;
        stk[++ tt] = A[0];
        Left[0] = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] <= stk[tt]) {
                Left[i] = 1 + tt;
                stk[++ tt] = A[i];
            } else {
                tt = 0;
                Left[i] = 1 + tt;
                stk[++ tt] = A[i];
            }
        }

        reverse(A.begin(), A.end());
        tt = 0;
        stk[++ tt] = A[0];
        Right[0] = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] <= stk[tt]) {
                Right[i] = 1 + tt;
                stk[++ tt] = A[i];
            } else {
                tt = 0;
                Right[i] = 1 + tt;
                stk[++ tt] = A[i];
            }
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            res = (res + Left[i] * Right[i]) % mod;
        }

        return res;
    }
};