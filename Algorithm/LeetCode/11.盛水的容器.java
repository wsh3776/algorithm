/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月4日 下午07:14:48
 *    @Filename: 11.接雨水.java
 */

/*  ====算法分析====
    双指针 时间复杂度:O(n) 一次扫描, 空间复杂度:O(1) 使用恒定的空间
    1.使用两个指针从首尾扫描数组，比较height[i]和height[j]，小的指针要先变化
    2.因为大的指针先变化一定不会使结果更优
    3.遍历一次数组，维护最大值即可
*/
class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int i = 0, j = n - 1, res = 0;
        while(i < j) {
            int h = Math.min(height[i], height[j]);
            res = Math.max(res, h * (j - i));
            if (height[i] < height[j]) i ++;
            else j --;
        }

        return res;
    }
}