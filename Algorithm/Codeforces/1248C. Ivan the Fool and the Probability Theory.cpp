#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int f[100005];

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    int n, m;
    cin >> n >> m;

    // 算出一维时的情况
    f[1] = 2, f[2] = 4;
    for (int i = 3; i < 100005; i ++) {
        f[i] = (f[i - 1] + 0ll + f[i - 2]) % mod;
    }

    cout << (f[n] - 2ll + f[m]) % mod << endl;


    return 0;
}