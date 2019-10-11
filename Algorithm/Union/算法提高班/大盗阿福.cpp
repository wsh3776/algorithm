#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int dp[N], w[N];

int main() {
    int T;
    cin >> T;
    
    while (T --) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i ++) {
            cin >> w[i];
        }
        
        dp[1] = w[1];
        for (int i = 2; i <= n; i ++) {
            dp[i] = max(dp[i - 2] + w[i], dp[i - 1]);  // choose or not
        }
        
        cout << dp[n] << endl;
    }
    
    
    return 0;
}