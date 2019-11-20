#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100005];

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

    int vertical = 0, horizontal = 0;
    for (int i = 0; i < n / 2; i ++) {
        vertical += a[i];
    }

    for (int i = n / 2; i < n; i ++) {
        horizontal += a[i];
    }

    cout << vertical * 1ll * vertical + horizontal * 1ll * horizontal << endl;

    return 0;
}