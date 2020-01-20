// 汉密尔顿回路，每个点访问一次，并回到原点，且最小
// DFS搜索城市的全排列
// 时间复杂度O(n!)
#include <iostream>

using namespace std;

const int N = 22;

int g[N][N];
int n;
int res;
bool st[N];
int ans = 0x3f3f3f3f;


void dfs(int u, int pre, int now) { // u表示已经选了几个城市
    if (u == n - 1) {
        res += g[pre][now];
        res += g[now][0];
        ans = min(res, ans);
        res -= g[pre][now]; // 恢复现场
        res -= g[now][0];
        return;
    }
    
    for (int i = 1; i < n; i ++) {
        if (!st[i]) {
            st[i] = true;
            res += g[pre][now];
            dfs(u + 1, now, i);
            res -= g[pre][now]; // 恢复现场
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }
    
    dfs(0, 0, 0);
    
    cout << ans << endl;


    return 0;
}
