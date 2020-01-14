// 2020年1月13日 星期一 11:06:23

// 按行搜索，所以不用row[N]
#include <iostream>

using namespace std;

const int N = 20; // 要比n的两倍大一些
char g[N][N];
bool col[N], dg[N], udg[N];
int n;

// bool数组用来判断搜索的下一个位置是否可行
// col列，dg对角线(左上到右下)，udg反对角线
// g[N][N]用来存路径

void dfs(int u) {
    if (u == n) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n ;j ++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // 对n个位置按行搜索
    for (int i = 1; i <= n; i ++) {
        // 剪枝(对于不满足要求的点，不能继续往下搜索)  对于dg[u + i - 1]，udg[n - u + i]，画个图就能确定表达式
        if (!col[i] && !dg[u + i - 1] && !udg[u - i + n]) {
            g[u + 1][i] = 'Q';                               // 从u = 1开始填
            col[i] = dg[u + i - 1] = udg[u - i + n] = true;
            dfs(u + 1);
            g[u + 1][i] = '.';                               // 恢复现场，这步必须有，因为这题不像排列数字那题都能被覆盖到
            col[i] = dg[u + i - 1] = udg[u - i + n] = false; // 恢复现场，不影响下一个分支的搜索，这步很关键
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n ;j ++) {
            g[i][j] = '.';
        }
    }
    
    dfs(0);
    
    return 0;
}

