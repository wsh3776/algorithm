#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int t, p;
    cin >> t >> p;

    double res;
    if (p >= 20) {
        res = t * 1.0 / (100 - p) * (p - 20) + 20 * 2 * t * 1.0 / (100 - p);
    } else {
        res = (t * 1.0 / (2 * (20 - p) + 80)) * 2 * p;
    }

    printf("%.6f", res);

    return 0;
}
