#include <iostream>
 
using namespace std;
 
 
int main() {
    int t;
    cin >> t;
    while (t --) {
        int b, p, f, h, c, price = 0, n1, n2;
        cin >> b >> p >> f >> h >> c;
 
        // 15 2 3
        if (h <= c) {
            n1 = min(b / 2, f);
            price += n1 * c;
            if (b / 2 > f) {
                n2 = min(b / 2 - f, p);
                price += n2 * h;
            }
        } else {
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