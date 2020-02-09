算法编程题的详细题解请看我的个人博客 [传送门](https://blog.csdn.net/qq_43827595)

算法是解决问题的思路、步骤和具体方法，每解出一个题，每看见一次<font color=green size=3 face=STHeiti>Accepted</font>的喜悦，是别人无法体会的


### 示例：LeetCode239.滑动窗口的最大值
[原题链接](https://leetcode.com/problems/sliding-window-maximum/)

#### 题目描述
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

**Example:**

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3

Output: [3,3,5,5,6,7]

Explanation: 
```
Window position                Max
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.




**算法分析：**
- 维护一个双向单调队列，`队列存放的是元素的下标`(用下标的好处时可以快速判断距离是否合法)。
- 假设该双端队列的队头是整个队列的最大元素所在下标，至队尾下标代表的元素值依次降低。
- 一开始单调队列为空。随着对数组的遍历过程中，每次插入元素前，首先需要看队头是否还能留在队列中，如果队头下标距离i超过了k，则应该出队。
- 同时需要维护队列的单调性，如果nums[i]大于或等于队尾元素下标所对应的值，则当前队尾再也不可能充当某个滑动窗口的最大值了，故需要队尾出队。
- 始终保持队中元素从队头到队尾单调递减。依次遍历一遍数组，每次队头就是每个滑动窗口的最大值所在下标

**C++代码**
```cpp
class Solution {
public:
    static const int N = 1e4;
    int q[N];
    int hh = 0, tt = 0;
   
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> res;
        
        for (int i = 0; i < n; i++) {
            while (hh < tt && i - q[hh] >= k) hh ++;
            while (hh < tt && nums[q[tt - 1]] <= nums[i]) tt --;
            q[tt ++] = i;

            if (i >= k - 1) res.push_back(nums[q[hh]]);
        }
        
        return res;
    }
};
```