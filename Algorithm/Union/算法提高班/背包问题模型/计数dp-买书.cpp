#include <iostream>

using namespace std;

const int N = 1010;

int f[N];

int main() {
    int m; // 都用m表示体积
    cin >> m;

    int v[] = {0, 10, 20, 50, 100}; // 第一个0是为了填数的
    f[0] = 1;  // 注意这个初始化一定要做
    for (int i = 1; i <= 4; i ++ ) {
        for (int j = v[i]; j <= m; j ++) {
            f[j] = f[j] + f[j - v[i]];
        }
    }

    cout << f[m] << endl;

    return 0;
}
