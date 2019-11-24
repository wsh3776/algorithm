#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

long long a[N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long res = 0;
    for (int i = 0; i < n; i ++) {
        res += a[i] * (n - 1 - i);
    }

    cout << res << endl;

}
