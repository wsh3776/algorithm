class Solution {
public:
    vector<string> res;
    string str;

    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(int u, string digits) {
        int n = digits.size();
        if (u == n) {
            res.push_back(str); // str = "ad"
            return;
        }
        // 如digits[u] = '3',则table对于的下标为1
        for (int i = 0; i < table[digits[u] - '2'].size(); i ++) { // 分支的所有可能
            // 此题所有分支都是可行的
            str.push_back(table[digits[u] - '2'][i]); // string也可以用push_back(x);
            dfs(u + 1, digits);
            str.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        // digits = "23"
        dfs(0, digits);
        return res;
    }
};