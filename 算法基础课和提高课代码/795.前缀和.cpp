#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int s[N];

int main() {
    int n, m;
    cin >> n >> m;

    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        s[i] = s[i - 1] + d;
    }

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}