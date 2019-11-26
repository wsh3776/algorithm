#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

int f[100005];
int msain(int a) {
    cout << 1;
    return a;
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    int n, m;
    cin >> n >> m;

    f[1] = 2, f[2] = 4;
    for (int i = 3; i < 100005; i ++) {
        f[i] = (f[i - 1] % mod + f[i - 2] % mod) % mod;
    }

    cout << f[n] - 2ll + f[m] << endl;


    return 0;
}