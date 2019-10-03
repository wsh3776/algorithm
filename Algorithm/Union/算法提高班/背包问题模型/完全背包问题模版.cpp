#include <iostream>

using namespace std;

const int N = 1010;

int f[N], v[N], w[N];

int main() {
    int n, m;   // 以后尽量用m表示体积
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }
   
    // 三重循环到两重到一维的最终优化版
    for (int i = 1; i <= n; i ++) {
        for (int j = v[i]; j <= m; j ++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;

    return 0;
}
