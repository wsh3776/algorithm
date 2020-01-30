// 2020年1月29日 星期三 17:16:41
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map <char, int> hash;
        int n = str.size();
        for (int i = 0; i < n; i ++) {
            hash[str[i]] ++;
        }

        // 找到第一个只出现一次的字符
        for (int i = 0; i < n; i ++) {
            if (hash[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};