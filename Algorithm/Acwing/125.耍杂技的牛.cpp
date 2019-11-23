// 贪心：考虑局部相邻两头牛的关系，只要w[i]+s[i] > w[i + 1] + s[i + 1] i = 0, 1, 2...从上往下
// 可以证明一定可以通过一次交换让最大值变小
// 另外两个题也是类似的，这算是贪心的一个经典题把
#include <iostream>
#include <algorithm>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
PII arr[50005];

bool cmp(PII A, PII B) {
    return A.x + A.y < B.x + B.y;
}

int main() {
    #ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
	
    int n; 
    cin >> n;
    
    for (int i = 0; i < n; i ++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + n, cmp); 
    
    // w1 + w2 + w3 - s4,i从上往下变大
    int sum = 0, mx = -arr[0].y;
    for (int i = 0; i < n - 1; i ++) {
        sum += arr[i].x;
        mx = max(mx, sum - arr[i + 1].y);
    }

    cout << mx << endl;


    return 0;
}
