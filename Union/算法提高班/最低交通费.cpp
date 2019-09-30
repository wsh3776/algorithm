// 最低交通费
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int v[N][N], f[N][N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif

    int n;
    cin >> n;

    memset(f, 0x3f, sizeof f);  // 题目要去min，故初始化边界要尽量大
    f[0][1] = 0; // 防止f[1][1]取值出错

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + v[i][j];
        }
    }

    cout << f[n][n] << endl;


    return 0;
}

// yxc
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 1e9;

int n;
int w[N][N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            scanf("%d", &w[i][j]);
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == 1 && j == 1) f[i][j] = w[i][j];  // 这样处理边界也是一种方法
            else
            {
                f[i][j] = INF;
                if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
                if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
            }
    
    printf("%d\n", f[n][n]);
    
    return 0;
}


// 路人甲
#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i, j, k) for(int i = j; i <= k; i++)

const int Max = 110;

using namespace std;
int n, dp[Max][Max];

int main()
{
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    For(i, 1, n)
        For(j, 1, n)
        {
            scanf("%d", &dp[i][j]);
            if(!(i == 1 && j == 1))
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
        }
    printf("%d\n", dp[n][n]);
    return 0;
}