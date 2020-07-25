#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int stk[N], tt;

int main() {
    int m, x;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;
        if (s == "push") {
            cin >> x;
            stk[tt ++] = x;
        } else if (s == "pop") {
            tt--;
        } else if (s == "empty") {
            if (tt <= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else if (s == "query") {
            cout << stk[tt - 1] << endl;
        }
    }

    return 0;
}