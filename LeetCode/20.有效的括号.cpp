/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月7日 星期六 10:31:11
 *    @Filename: 20.有效的括号.cpp
 */

class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') { // 如果最后有剩余，用stk.empty()去判断
                stk.push(s[i]);
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(')return false;
                stk.pop();
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else if (s[i] == '}') {
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
            }
        }

        return stk.empty(); // 这个返回很妙
    }
};