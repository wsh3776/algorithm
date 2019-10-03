// 整数划分 只用1 2 3
#include <iostream>

using namespace std;

const int N = 10010;

int f[N];

int main() {
    int m;
    cin >> m;
    
    int v[] = {0, 1, 2, 3}; // 第一个0是为了填数的
    f[0] = 1;  // 注意这个初始化一定要做
    for (int i = 1; i <= 3; i ++ ) {
        for (int j = v[i]; j <= m; j ++) {
            f[j] = f[j] + f[j - v[i]];
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}