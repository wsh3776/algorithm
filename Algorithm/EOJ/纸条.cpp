#include <algorithm>
#include <iostream>

using namespace std;

int a[500005];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif

    int n, m, k;
    long long x;
    cin >> n >> m >> k >> x;

    // 4 表示 1 0
    // 3 表示 0 2
    // 找到规律 x - 1，然后再取k进制即可
    int i = 0; 
    x--;
    while(x) {
        a[i] =  x % k;
        x /= k;
        i ++;
    }

    // c##nb sl 从高到低
    string s, tmp, res = "";
    cin >> s;
    // c##nb
    for (int i = 0; i < m; i ++) {
        cin >> tmp;
        sort(tmp.begin(), tmp.end());
        res += tmp[a[m - i - 1]]; // s... l...
    }

    for (int i = 0, j = 0; i < s.size(); i ++) {
        if (s[i] == '#') {
            cout << res[j]; 
            j ++;
        } else  cout << s[i];
    }

    return 0;
}

