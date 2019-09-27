// A. There Are Two Types Of Burgers
// http://codeforces.com/contest/1207/problem/A
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t --) {
        int b, p, f, h, c, price = 0, n1, n2;
        cin >> b >> p >> f >> h >> c;

        // 15 2 3
        if (h <= c) {
            n1 = min(b / 2, f);
            price += n1 * c;
<<<<<<< HEAD
            if (b /  > f) {
=======
            if (b / 2 > f) {
>>>>>>> update9.7
                n2 = min(b / 2 - f, p);
                price += n2 * h;
            }
	    
            n1 = min(b / 2, p);
            price += n1 * h;
            if (b / 2 > p) {
                n2 = min(b / 2 - p, f);
                price += n2 * c;
            }
        }

        cout << price << endl;
    }
    return 0;
}
