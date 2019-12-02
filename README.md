@Author: Wilson79

@Blogs: https://blog.csdn.net/qq_43827595

哈夫曼问题的最优解
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    // 小根堆
    priority_queue <int, vector<int>, greater<int> > heap;

	for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        heap.push(x);
	}
    
    int res = 0;
    while(heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();

        res += a + b;
        heap.push(a + b);
    }

    cout << res << endl;

    return 0;
}
```

完全背包问题
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

