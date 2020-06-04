// 高精度 / 低精度
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// A / b, 商是 C，余数是 r
vector<int> div(vector<int> &A, int b, int &r) { // r必须是引用
    vector<int> C;

    // 核心：r = 10 * r + A[i] 从高位开始
    for (int i = A.size() - 1; i >= 0; i--) { // A = [A0(个位), A1,A2, ...]
        r = r * 10 + A[i];
        C.push_back(r / b); // C = [Ck(前导零),...,C1,C0(个位)]
        r %= b;
    }

    reverse(C.begin(), C.end()); // 记得倒序

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r = 0;
    auto C = div(A, b, r); // 余数r靠引用返回

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl << r << endl;

    return 0;
}