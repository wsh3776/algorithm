#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int flag = 0;
    while (T--) {
        int l, r, n;
        cin >> l >> r >> n;
        l ++;

        // 虽然是[l + 1, r]，但用这范围如果出题人的数是最后一个，那最后一次没有猜就退出了循环，所以保险点直接用while(true)

        while (true) {
            int mid = l + r >> 1;
            cout << mid << endl;
            string s;
            cin >> s;
            if (s == "CORRECT") break;

            if (s == "TOO_SMALL")
                l = mid + 1;
            else
                r = mid;
        }
    }
}