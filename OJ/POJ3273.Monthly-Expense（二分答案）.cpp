#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 7;
int n, m;
LL a[N];
LL l = 0, r = 0;

bool check(int x, int m) {
    LL sum = 0;
    m --; // 一开始一定要用1天
    // 2 4 | 3 2 | 3  (m = 7)
    for (int i = 0; i < n; i ++) {
        sum += a[i];
        if (sum > x) {
            sum = a[i];
            m --;
            if (a[i] > x) return false; // 如果随意扩大了范围，那这句话一定要写
        }
    }
    return m >= 0;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    cin >> n >> m;

    // 找到答案可能的区间
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        // r += a[i];
        // l = max(l, a[i]);
    }

    l = -2e9, r = 2e9; // 用无穷大设范围是可以的，但要注意check函数
    while (l < r) {
        LL mid = (l + r) >> 1;
        if (check(mid, m)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;

    return 0;
}