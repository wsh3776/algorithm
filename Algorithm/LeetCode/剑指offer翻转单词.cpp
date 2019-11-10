class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int n = s.size();
        
        // 找出来某个连续的一段——非常经典
        for(int i = 0; i < n; i ++) {
            int j = i;
            while (j < n && s[j] != ' ') j ++;
            reverse(s.begin() + i, s.begin() + j);
            i = j; // i此时指向空格，后面会+1，找下一个连续段
        }
        
        return s;
    }
};




