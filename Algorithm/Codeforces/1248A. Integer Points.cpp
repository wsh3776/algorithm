// Statistics odd and even number and multiply them
#include <iostream>
#include <cstring>

using namespace std;

int cnt1[2], cnt2[2];

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    int t = 0;
    cin >> t; 
    while (t --) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));

        int n1, n2, p, q;
        cin >> n1;
        for (int i = 0; i < n1; i ++) {
            cin >> p;
            if (p & 1) cnt1[0] ++; // sum of odd number of p
            else cnt1[1] ++;
        }

        cin >> n2;
        for (int i = 0; i < n2; i ++) {
            cin >> q;
            if (q & 1) cnt2[0] ++; // sum of odd number of q
            else cnt2[1] ++;
        }

        cout << cnt1[0] * 1ll * cnt2[0] + cnt1[1] * 1ll * cnt2[1] << endl;
    }


    return 0;
}
