// 这题一看有 500 多人会做，一定是个签到题，一定很水的，别想复杂了，条件都是来吓人的
#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
	
    int n, m;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s;

    cin >> m;
    for (int i = 1; i <= m; i ++) cin >> s;
    
    if (n > m) cout << "Cuber QQ" << endl;
    else cout << "Quber CC" << endl;


    return 0;
}
