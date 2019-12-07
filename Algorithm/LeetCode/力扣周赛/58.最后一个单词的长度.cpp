/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月6日 上午09:33:06
 *    @Filename: 58.最后一个单词的长度.cpp
 */

// 求连续的一段区间的经典练习题
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while(j < n && s[j] == ' ') j ++;
            if (j == n) break;
            i = j;
            while(j < n && s[j] != ' ') j ++;
            res = j - i; 
            i = j;   // 注意最后要把j赋值给i
        } 

        return res;
    }
};