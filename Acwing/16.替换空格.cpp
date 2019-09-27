/*
 * @Author: shwei
 * @Date: 2019-08-16 15:41:32
 * @LastEditors: shwei
 * @LastEditTime: 2019-08-24 08:55:10
 */
// 输入："We are happy."

// 输出："We%20are%20happy."

class Solution {
public:
    string replaceSpaces(string &str) {
        string res = "";
        for (auto x : str) {
            if (x == ' ') {
                res += "%20";
            } else {
                res += x;
            }
        }
        return res;
    }
};