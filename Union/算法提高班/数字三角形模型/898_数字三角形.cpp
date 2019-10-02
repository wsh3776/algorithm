#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N], f[N][N];

int main() {  
    #ifdef ONLINE_JUDGE
      #else
      freopen("in.txt","r",stdin);
      #endif
      

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            scanf("%d", &a[i][j]);

    // 求最大值，故f初始化为负无穷
    for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= i + 1; j ++ )
            f[i][j] = -INF;

    f[1][1] = a[1][1]; // 边界情况
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ ) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }

    // 求最大的一条路径
    int res = -INF;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);

    printf("%d\n", res);
    return 0;
}
