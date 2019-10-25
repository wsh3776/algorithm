#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M];       // 用数组模拟队列
bool st[N][N];  // state标记数组 防止我们去重复遍历某个点,如果重复遍历了，我们的算法时间复杂度就没有保证了


bool bfs(int sx, int sy) { // sx: state x
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    while(hh <= tt) { // 队列不空时
        PII t = q[hh ++]; // 取出后要出栈

        // 八连通 挖掉中间那个店
        for (int i = t.x - 1; i <= t.x + 1; i ++) {
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                if (i == t.x && j == t.y) continue;
                if (i >= 0 && i < n && j >= 0 && j < m && g[i][j] == 'W' && !st[i][j]) {
                    q[++ tt] = {i, j};
                    st[i][j] = true; // 表示这个点已经被走过了
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); // 开启这个可以快200ms左右
    cin >> n >> m;

    // 如果只知道行数，但列数不同可以用 scanf("%s", g[i]); 读入数据
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}


