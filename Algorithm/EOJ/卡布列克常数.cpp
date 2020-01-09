#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
    if (a > b) return true;
    return false;
}

void solve(int n) {
    int tmp = n;

    while(tmp != 6174) {
        string s = to_string(tmp);
        sort(s.begin(), s.end(), cmp); // biggest
        int mx = stoi(s);
        sort(s.begin(), s.end()); // smallest
        int mn = stoi(s);
        tmp = mx - mn;
        cout << mx << "-" << mn << "=" << tmp << endl;
    }

}

int main() {

    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    solve(n);



    return 0;
}