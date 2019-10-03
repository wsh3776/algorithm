// 这题n = 5000可以n^2,否则到50000需要用LIS的贪心优化版本

// pair排序后LIS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef

const int N = 5010;


// yxc
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII q[N];
int f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &q[i].first, &q[i].second);
    sort(q, q + n);
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        f[i] = 1;
        for (int j = 0; j < i; j ++ )
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
        
        res = max(res, f[i]);
    }
    
    printf("%d\n", res);
    
    return 0;
}

// 路人甲
#include<bits/stdc++.h>
using namespace std;
struct oppo {
    int w, s;
} a[5005];

int n, t;
int f[5005];
bool lxl(oppo a, oppo b) {
    return a.w < b.w;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].s;

    sort(a + 1, a + n + 1, lxl);
    
    for(int i = 1; i <= n; i++)
        for(int j = i - 1; j >= 0; j--)
            if(j == 0 || a[j].s < a[i].s)
                f[i] = max(f[i], f[j] + 1);
    
    for(int i = 1; i <= n; i++)
        t = max(t, f[i]);
    cout << t << endl;
    return 0;
}

