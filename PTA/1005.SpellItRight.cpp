#include <iostream>

using namespace std;

const string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {

    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    
    string s;
    cin >> s;
 
    // s = "12345"
    int n = s.size();
    int tmp = 0;
    for (int i = 0; i < n; i ++) {
        tmp += s[i] - 48;       
    }

    // tmp = 15
    int k = to_string(tmp).size(), digit = 1;
    for (int i = 1; i <= k - 1; i ++) digit *= 10;
    while(k > 1) {
        k --;
        cout << words[tmp/digit] << " ";
        tmp %= digit;
        digit /= 10;
    }

    cout << words[tmp];
    return 0;
}
