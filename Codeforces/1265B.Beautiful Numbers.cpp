/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月10日 星期二 16:36:54
 *    @Filename: 1265B.Beautiful Numbers.cpp
 */

/*  ====算法分析====
    模拟 时间复杂度:O(n), 空间复杂度:O(n)
    例如：4 5 1 3 2 6
    从1到n，每次找到最左边和最右边的元素，然后看下他们的距离是不是等于m即可
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 7;

int ans[N];
int pos[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        pos[k] = i; // 记录数的位置1~n
    }

    vector <int> ans;
    int l = 0x3f3f3f3f, r = -1;
    for (int i = 1; i <= n; i ++) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        if (r - l + 1 == i) ans.push_back(1);
        else ans.push_back(0);
    }

    for (auto x : ans) cout << x;
    cout << endl;
}


int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif
    
    int t;
    cin >> t;
    while(t --) solve();
}