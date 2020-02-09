// https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    #ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
    
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    string res = "";
    int n = s.size(), t = 0;
    for (int i = 0; i < n; i ++) {
        res += to_string(((s[i] - 48) * 2 + t) % 10);
        t = ((s[i] - 48)*2 + t) / 10;
    }
    if (t > 0) res += "1";

    reverse(res.begin(), res.end());
    string s1 = s, s2 = res;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << res << endl;

    return 0;
}

