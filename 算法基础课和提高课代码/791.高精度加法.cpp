#include <iostream>

using namespace std;

vector<int> add(vector <int>&A, vector<int> &B) {
    vector<int> C;

    int t = 0; // 用 t 表示 Ai + Bi + t 的和
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10; // 进位
    }
    if (t) C.push_back(t);

    return C;
}

int main () {
    string a, b;
    cin >> a >> b; // a = "1234" b = "89"

    vector <int> A, B;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0'); // A = [4,3,2,1]
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0'); // B = [9,8]

    auto C = add(A, B); // C = [3,2,3,1]

    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];

}