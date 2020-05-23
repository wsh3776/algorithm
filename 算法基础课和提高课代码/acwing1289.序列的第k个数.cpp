#include <iostream>

using namespace std;

const int N = 200907;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        if (b - a == c - b) {
            cout << a + (k - 1) * (b - a) << endl;
        } else {
            cout << a * qmi(b / a, k - 1, mod) % mod << endl;
        }
    }

    return 0;
}