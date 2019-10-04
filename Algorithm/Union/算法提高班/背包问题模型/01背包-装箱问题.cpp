// 装箱问题 将物体的体积同时看做体积和价值，问题转换为在不超过最大容量的情况下，最大价值是多少
#include <iostream>

using namespace std;

const int N = 20020;

int f[N], v[N]; // w[N] = v[N];

int main() {
    int m, n;
    cin >> m >> n;
    
    for (int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= v[i]; j --) {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    
    cout << m - f[m] << endl;
    
    return 0;
}