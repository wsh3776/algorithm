#include <iostream>

using namespace std;

typedef long long LL;

const int N = 3030;

LL f[N], v[N]; // 数据范围变大了

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = v[i]; j <= m; j ++) {
            f[j] = f[j] + f[j - v[i]];
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}
