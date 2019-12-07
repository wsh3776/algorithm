/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月6日 上午09:44:29
 *    @Filename: 42.接雨水.cpp
 */

/*  ====算法分析====
    三次线性扫描 时间复杂度:O(n), 空间复杂度:O(n) 都是线性扫描
    核心：每个矩形条上方所能接受的水的高度是由它左边最高的矩形和右边最高的矩形所决定的
    先预处理出每个矩形左右两边的最大矩形高度，然后在遍历一遍数组即可
*/
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        if (n == 0) return 0;
        int left[n], right[n];
        left[0] = height[0];
        for (int i = 1; i < n; i ++)
            left[i] = max(left[i - 1], height[i]);


        right[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j --)
            right[j] = max(right[j + 1], height[j]);

        for (int i = 0; i < n; i++) {
            res += min(left[i], right[i]) - height[i];
        }

        return res;
    }
};

/*  ====算法分析====
    栈 时间复杂度:O(n), 空间复杂度:O(n)
    维护一个单调递减的栈,while循环不断计算U型坑的雨水量
*/

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        if (n == 0) return 0;
        stack <int> stk; // 存下标
        
        for (int i = 0; i < n; i ++) {
            while(!stk.empty() && height[stk.top()] < height[i]) {
                int bottom = stk.top();
                stk.pop(); // pop后栈顶为U的左侧边界
                if (!stk.empty()) {
                    res += (i - stk.top() - 1) * (min(height[stk.top()], height[i]) - height[bottom]);
                }
            }

            stk.push(i); // 栈为空或值递减则入栈
        } 
        return res;
    }
};













