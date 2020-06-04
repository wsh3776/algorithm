#include <iostream>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    // 区间 DP 枚举套路：长度+左端点 
    //（一个点算一个单位长度）
    for (int len = 2; len <= n; len ++) { // 一般从len=2开始（len=1用于初始化）
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1; // 自动得到右端点
            f[i][j] = 1e8;
            for (int k = i; k <= j - 1; k ++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;


    return 0;
}