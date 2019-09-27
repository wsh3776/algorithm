/*
 * @Author: shwei
 * @Date: 2019-08-23 19:56:30
 * @LastEditors: shwei
 * @LastEditTime: 2019-08-23 20:06:54
 */
/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */
class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int n = A.size(), sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += A[i];
        }

        if (sum % 3 != 0) {
            return false;
        }

        int s = sum / 3;

        sum = 0;
        for (int i = 0; i < n; i ++) {
        	sum += A[i];
        	if (sum == s) {
        		sum = 0;
        		for (int j = n - 1; j > i + 1; j --) {
        			sum += A[j];
        			if (sum == s) {
        				return true;
        			}
        		}
                return false;
        	}
        }

        return false;
    }
};

