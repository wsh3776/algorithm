// 前缀和
// N个目标相当于 N 次操作 
// R 很大，只要取 50001 就一定能保住所有的目标

#include <iostream>

using namespace std;

const int N = 5002;

int s[N][N];

int main() {
    int q, R;
    cin >> q >> R;
    R = min(R, 5001);

    while (q --) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
    }

    for (int i = 1; i < N; i ++) {
        for (int j = 1; j < N; j++) {
            s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int res = 0;
    for (int i = R; i < N; i ++) {
        for (int j = R; j < N; j ++) {
            res = max(res, s[i][j] - s[i][j - R] - s[i - R][j] + s[i - R][j - R]);
        }
    }

    cout << res << endl;

    return 0;
}