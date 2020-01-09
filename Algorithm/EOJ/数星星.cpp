/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 15:33:34
 *    @Filename: 数星星.cpp
 */

#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    long long n, a, b;
    cin >> n;
    long long minx = 100007, maxx = -1;
    long long miny = 100007, maxy = -1;
    while(n --) {
        cin >> a >> b;
        minx = min(minx, a), maxx = max(maxx,a);
        miny = min(miny, b), maxy = max(maxy,b);
    }

    cout << max(maxx - minx, maxy - miny) * max(maxx - minx, maxy - miny) << endl;;
    return 0;
}
