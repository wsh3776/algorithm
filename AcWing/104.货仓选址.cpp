#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main() {
    #ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
	
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
  
    int res = 0;
    for (int i = 0; i < n; i ++) {
        res += abs(a[i] - a[n / 2]);  
    }
    
    cout << res << endl;


    return 0;
}
