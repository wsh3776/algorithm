#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int b[N];

int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            b[l] += 1, b[r + 1] -= 1;
        }
        for (int i = 1; i <= n; i++)
            b[i] += b[i - 1];

        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";

        cout << endl;

        memset(b, 0, sizeof b);
    }

    return 0;
}