// 2 3 9

// 8
#include <bits/stdc++.h>
using namespace std;

int main()
{
<<<<<<< HEAD
=======
    freopen("in.txt", "r", stdin);
>>>>>>> update9.7
    long long ans = 1, i, j, k, m, n, b, p;
    scanf("%lld%lld%lld", &b, &m, &p);
    while (m > 0)
    {
        if (m % 2 == 1)
            ans = ans * b % p;
        b = b * b % p;
        m = m >> 1;
    }
    printf("%lld", ans % p);
    return 0;
}


