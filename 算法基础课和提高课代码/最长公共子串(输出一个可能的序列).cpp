#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5007;

int f[N][N];
int n, m;
string a, b;

void getString(int i, int j, int len) { // len表示最大公共子序列的长度
    string s;

    int i, j;
    for (i = 1; i <= n; i ++) {
        for (j = 1; j <= m; j ++) {
            if (f[i][j] == res) {
                break; // 找到一个就行了
            }
        }
    }
    while (i >= 1 && j >= 1 && a[i - 1] == b[j - 1]) { // 最长公共子串是连续的
        s += a[i - 1];
        i --;
        j --;
    }
    
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    // "f[i][j]"表示所有A[1,...,i]与B[1,...,j]的公共子序列且以a[i],b[j]结尾的集合，属性：最大值
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) { 
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = 0;
            }
        res = max(res, f[i][j]);
        }
    }

    int len = res; // 最长公共子串的长度
    if (len == 0) cout << -1 << endl;
    else getString(n, m, res);

    return 0;
}