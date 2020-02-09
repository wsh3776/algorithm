// 未解决
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif


    int A, B, a, b;
    cin >> A >> B >> a >> b;
    if (A < B) swap(A, B);
    if (a < b) swap(a, b);

    int res = 0;
    if (A < a || B < b) cout << -1 << endl;
    else {
        int t = B;
        while(b < t) {
            res ++;
            t = (int)ceil(1.0 * t / 2); // 这一次后的最小长度
        }

        t = A;
        while(a < t) {
            res ++;
            t = (int)ceil(1.0 * t / 2); // 这一次后的最小长度
        }

        int tmp = res;
        res = 0;
        t = A;
        while(b < t) {
            res ++;
            t = (int)ceil(1.0 * t / 2); // 这一次后的最小长度
        }

        t = B;
        while(a < t) {
            res ++;
            t = (int)ceil(1.0 * t / 2); // 这一次后的最小长度
        }

        res = max(tmp, res);

        cout << res << endl;
    }


    return 0;
}
