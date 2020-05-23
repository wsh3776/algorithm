// "1437983724598723459872349857982347598234759"
//              "234789235798345798347589347539"

#include <iostream>
#include <vector>

using namespace std;

string addString(string s1, string s2) {
    vector<int> A, B, C;
    for (int i = s1.size() - 1; i >= 0; i--)
        A.push_back(s1[i] - 48);
    for (int i = s2.size() - 1; i >= 0; i--)
        B.push_back(s2[i] - 48);

    if (A.size() < B.size()) addString(s2, s1);

    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t > 0) C.push_back(t);

    string res = "";
    for (int i = C.size() - 1; i >= 0; i--)
        res += to_string(C[i]);
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << addString(s1, s2) << endl;

    return 0;
}
