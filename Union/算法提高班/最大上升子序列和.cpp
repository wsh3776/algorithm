#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++ ) {
        f[i] = a[i]; // 巧妙处理了长度为1的情况
        for (int j = 1; j < i; j ++ )
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + a[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);
    printf("%d\n", res);

    return 0;
}

// 快读函数
#include<cstdio>
#include<algorithm>
#define N 1005
#define f(i,st,sd) for (int i=st;i<=sd;i++)
using namespace std;
int n, a[N], f[N];

inline int read() {
    char c = getchar();
    int ans = 0;
    while(c > '9' || c < '0') c = getchar();
    while(c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
    return ans;
}

int main() {
    n = read();
    f(i, 1, n) a[i] = read();

    f(i, 1, n) {
        f[i] = a[i];
        f(j, 1, i - 1) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    int k = 1;
    
    f(i, 2, n) if (f[i] > f[k]) k = i;
    printf("%d", f[k]);
    return 0;
}