#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    while(n --) {
        string s;
        cin >> s;
        int hour   = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(2, 2));
        int second = stoi(s.substr(4, 2));

        int totsecond = hour * 3600 + minute * 60 + second;

        int t = totsecond % (a + b + c);
        if (t == 0) t = a + b + c;
        if (t <= a) {
            if (s[6] != 'L') cout << s.substr(7, 8) << endl;
        } else if (t <= a + b) {
            if (s[6] != 'S') cout << s.substr(7, 8) << endl;
        } else {
            if (s[6] != 'R') cout << s.substr(7, 8) << endl;
        }
    }

    return 0;
}
