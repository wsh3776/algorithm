#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int a[N], stk[N], tt;

int main() {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i ++) cin >> a[i];

    // 维护单调增栈（存下标比较好）
    for (int i = 0; i < n; i ++) {
        while (tt > 0 && stk[tt - 1] >= a[i]) tt --;
        if (tt == 0) cout << -1 << " ";
        else cout << a[stk[tt - 1]] << " ";

        stk[tt ++] = i;
    }

    return 0;
}