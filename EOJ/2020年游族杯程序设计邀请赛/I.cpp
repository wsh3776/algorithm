#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s = "";

    s += "b";

    for (int i = 1; i < k; i ++) s += "a";

    for (int i = 1; i <= n - k; i++) s += "c";
    

    cout << s << endl;

    return 0;
}