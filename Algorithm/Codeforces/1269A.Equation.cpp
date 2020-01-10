#include <iostream>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    int n;
    cin >> n;
    
    cout << 9 * n << " " << 8 * n << endl;

    return 0;
}
