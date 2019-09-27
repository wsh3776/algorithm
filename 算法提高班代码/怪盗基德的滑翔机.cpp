// me
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N], f[N];

int main() {
    int T;
    cin >> T;
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

        for (int i = 1; i <= n; i ++ ) {
            f[i] = 1;
            for (int j = 1; j < i; j ++ )
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
        }

        int res1 = 0;
        for (int i = 1; i <= n; i ++ ) res1 = max(res1, f[i]);

        // 反向
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; i ++ ) {
            f[i] = 1;
            for (int j = 1; j < i; j ++ )
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
        }

        int res2 = 0;
        for (int i = 1; i <= n; i ++ ) res2 = max(res2, f[i]);

        printf("%d\n", max(res1, res2));
    }
    return 0;
}

// yxc 求所有a[i]的最大值时可以直接在第二重循环中做
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N], f[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

        // 正向求解LIS问题
        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            f[i] = 1;
            for (int j = 1; j < i; j ++ )
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        // 反向求解LIS问题
        for (int i = n; i; i -- ) {
            f[i] = 1;
            for (int j = n; j > i; j -- )
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        printf("%d\n", res);
    }

    return 0;
}