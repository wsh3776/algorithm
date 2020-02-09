#include <iostream>
#include <cstring>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 107;

int n, m;
int g[N][N];
PII q[N * N];
bool st[N][N];
int dist[N][N];

void bfs() {
    memset(dist, 0, sizeof dist);
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    st[0][0] = true;

    while(hh <= tt) {
        PII t = q[hh ++];
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (g[a][b] == 1 || st[a][b]) continue;

            dist[a][b] = dist[t.x][t.y] + 1;
            q[++ tt] = {a, b};
            st[a][b] = true;
        }
    }
    cout << dist[n - 1][m - 1] << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    bfs();
}




