// yxc 三维数组
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int n;
int w[N][N];
int f[N * 2][N][N];

int main()
{
    scanf("%d", &n);
    
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) w[a][b] = c;
    
    for (int k = 2; k <= n + n; k ++ )
        for (int i1 = 1; i1 <= n; i1 ++ )
            for (int i2 = 1; i2 <= n; i2 ++ )
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
    
    printf("%d\n", f[n + n][n][n]);
    return 0;
}

// 路人甲
#include<bits/stdc++.h>

using namespace std;


const int N=15;
int a[N][N];
int f[N][N][N][N];

int main()
{
    int n;
    cin>>n;
    int x,y,num;

    while(cin>>x>>y>>num,x!=0||y!=0||num!=0)
    {
        a[x][y]=num;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int t=1;t<=n;t++)
                {
                    f[i][j][k][t]=max(max(f[i-1][j][k-1][t],f[i-1][j][k][t-1]),max(f[i][j-1][k-1][t],f[i][j-1][k][t-1]))
                    +a[i][j]+a[k][t];
                    if(i==k&&j==t) f[i][j][k][t]-=a[i][j];
                }
            }
        }
    }
    cout<<f[n][n][n][n]<<endl;

    return 0;
}

