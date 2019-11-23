// https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    #ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
    
    // n <= m
    string s,sk;
    cin >> s >> sk;
    reverse(s.begin(), s.end());
    reverse(sk.begin(), sk.end());


    string res = "";
    if (s.size() > sk.size()) swap(s, sk);
    int n = s.size(), m = sk.size(), t = 0;
    
    for (int i = 0; i < n; i ++) {
        res += to_string(((s[i] - 48) + (sk[i] - 48) + t) % 10);
        t = ((s[i] - 48) + (sk[i] - 48) + t) / 10;
    }

    for (int i = n; i < m; i ++) {
        res += to_string(( (sk[i] - 48) + t) % 10);
        t = ( (sk[i] - 48) + t) / 10;
    }
    if (t > 0) res += "1";

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}

