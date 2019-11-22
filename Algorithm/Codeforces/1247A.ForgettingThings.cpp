#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;

    if (a == 9 && b == 1) cout << 9 << " " << 10 << endl;
    else if (a - b != 0 && a - b != -1) cout << -1 <<endl;
    else {
        if(a == b) cout << 10 * a << " " << 10 * b + 1 << endl;
        else {
            cout << 10 * a + 9 << " " << 10 * b << endl;
        }
    }
    return 0;
}
