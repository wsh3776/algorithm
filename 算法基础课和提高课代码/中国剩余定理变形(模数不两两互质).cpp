#include <iostream>

using namespace std;

// x = kimi + ai

// x = k[m1, m2] + k1m1 + a1;

// k1 + k*m2/ d

// m1k1 - m2k2 = a2 - a1;

int main() {
    int n;
    cin >> n;

    bool has_answer = true;

    int m1, a1, m2, a2, k1, k2;
    cin >> m1 >> a1; // 当前合并好的方程

    for (int _ = 0; _ < n - 1; _ ++) {
        cin >> m2 >> a2;
        // m1k1 - m2k2 = (m1, m2);
        int d = exgcd(m1, m2, k1, -k2);
        if ((a2 - a1) % d != 0) {
            has_answer = false;
        } else {
            int t = m2 / d;
            k1 = (k1 % t + t) % t;
            a1 = k1*m1+a1;     
            m1 = m1 * m2 / d;
        }
    }

    // x = k1m1 + a1;  
    if (has_answer) {
        cout << (x % m1 + m1) % m1 << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}