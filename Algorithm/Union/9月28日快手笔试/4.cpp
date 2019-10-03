// 丢手绢 暴80%
#include <iostream>

using namespace std;

const int N = 10010;

int T[N], q[N];

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> T[i];
        q[i] = T[i];
        // cout << q[i] << endl;
    }

    int flag = 0, res = 0;
    while (flag == 0) {
        for (int i = 1; i <= n; i ++) {
            q[i] = T[q[i]];
            //cout << q[i] << endl;
            if (q[i] == i) {
                flag = 1;
                break;
            }
        }
        res ++;
    }

    cout << res + 1 << endl;

    return 0;
}
