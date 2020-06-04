#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5007;

int f[N][N];
int n, m;
string a, b;

void getString(int i, int j, int len) { // len表示最大公共子序列的长度
    string s;
    while (i >= 1 && j >= 1) { // 倒序还原
        if (a[i - 1] == b[j - 1]) {
            s += a[i - 1];
            i--, j--;
        } else {
            if (f[i - 1][j] >= f[i][j - 1]) { // 说明是有f[i-1][j]转移过来的
                i --;
            } else j --;
        }
    }
    
    reverse(s.begin(), s.end());
    cout << s << endl;
    
}

int main() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    // "f[i][j]"表示所有A[1,...,i]与B[1,...,j]的公共子序列的集合，属性：最大值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) { 
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]); // 集合"f(i-1,j)"和"f(i,j-1)"有相交部分，但求最值可重复
            }
        }
    }

    int len = f[n][m]; // 最长公共子序列的长度
    if (len == 0) cout << -1 << endl;
    else getString(n, m, f[n][m]);

    return 0;
}