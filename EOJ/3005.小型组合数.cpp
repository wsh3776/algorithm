#include <iostream>

using namespace std;

const int N = 100;

long long c[N][N];

void init() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0) c[i][j] = 1;
            else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    init(); // 预处理

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << "case #" << i << ":" << endl;
        cout << c[a][b] << endl;
    }


    return 0;
}
