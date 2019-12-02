作者：Wilson79

个人博客地址：
https://blog.csdn.net/qq_43827595

- 示例：完全背包代码模版

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N], f[N];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {    // 正序
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            // 朴素：f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]) 
            // f[i][j - v[i]] + w[i] = max(x, x, x, ...)
        }
    }
    
    cout << f[m] << endl;
}

```
