// 动态规划求解并输出所有LCS
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

string X = "acbd";
string Y = "abedc";
vector<vector<int>> table; // 动态规划表
set<string> setOfLCS;      // set保存所有的LCS

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * 构造表，并返回X和Y的LCS的长度
 */
int lcs(int m, int n) {
    // 表的大小为(m+1)*(n+1)
    table = vector<vector<int>>(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            // 第一行和第一列置0
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    return table[m][n];
}

/**
 * 求出所有的最长公共子序列，并放入set中
 */
void traceBack(int i, int j, string lcs_str, int lcs_len) {
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str.push_back(X[i - 1]);
            --i;
            --j;
        } else {
            if (table[i - 1][j] > table[i][j - 1])
                --i;
            else if (table[i - 1][j] < table[i][j - 1])
                --j;
            else // 相等的情况
            {
                traceBack(i - 1, j, lcs_str, lcs_len);
                traceBack(i, j - 1, lcs_str, lcs_len);
                return;
            }
        }
    }

    string str(lcs_str.rbegin(), lcs_str.rend()); // lcs_str逆序
    if ((int)str.size() == lcs_len)               // 判断str的长度是否等于lcs_len
        setOfLCS.insert(str);
}

void print() {
    set<string>::iterator beg = setOfLCS.begin();
    for (; beg != setOfLCS.end(); ++beg)
        cout << *beg << endl;
}
int main() {
    int m = X.length();
    int n = Y.length();
    int length = lcs(m, n);
    cout << "The length of LCS is " << length << endl;

    string str;
    traceBack(m, n, str, length);
    print();

    return 0;
}