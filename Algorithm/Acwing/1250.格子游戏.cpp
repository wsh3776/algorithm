#include <iostream>

using namespace std;

const int N = 210;

int p[N * N];
int n, m;
int x, y, a, b;
char c;


int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n * n; i ++) {
        p[i] = i;
    }

    int i;
    for (i = 1; i <= m; i ++) {
        cin >> x >> y >> c;
        x--, y--;
        a = x * n + y;
        if (c == 'R') {
            b = x * n + y + 1;
        } else {
            b = (x + 1) * n + y;
        }

        if (find(a) != find(b)) {
            p[find(a)] = find(b);
        } else {
            cout << i << endl;
            break;
        }
    }

    if (i > m) cout << "draw" << endl;

    return 0;
}