#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int q[N], hh, tt;


int main() {
    int m, x;
    cin >> m;

    while (m --) {
        string s;
        cin >> s;
        if (s == "push") {
            cin >> x;
            q[tt ++] = x;
        } else if (s == "pop") {
            hh  ++;
        } else if (s == "empty") {
            if (hh < tt) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else if (s == "query") {
            cout << q[hh] << endl;
        }
    }
  

    return 0;
}