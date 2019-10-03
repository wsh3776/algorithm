// n = n1 + n2 + ... + nk;
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

int main() {
    cin >> n;
   
    // 三重循环到两重到一维的最终优化版
    f[0] = 1; // 初始化空集为1 一定不要忘记
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            f[j] = (f[j] + f[j - i]) % mod;
            // 朴素：f[i][j] = f[i - 1][j - i] + f[i - 1][j];
        }
    }
    
    cout << f[n] << endl;

    return 0;
}