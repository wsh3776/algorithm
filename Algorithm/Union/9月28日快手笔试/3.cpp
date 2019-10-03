// 有趣的最大池化 暴力60%
#include <iostream>
#include <vector>

using namespace std;

const int N = 2000100;

int q[N];
vector <int> res;
int main() {
	#ifdef ONLINE_JUDGE
	#else
    	freopen("in.txt","r",stdin);
    	//freopen("out.txt","w",stdout);
	#endif

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> q[i];
	}


	cin >> m;

	for (int i = 0; i + m - 1 < n; i ++) {
		int mx = -0x3f3f3f3f;
		for (int j = i; j < m + i; j ++) {
			mx = max(mx, q[j]);
		}
		res.push_back(mx);
	}

	for (int i = 0; i < res.size(); i ++) {
		cout << res[i] << " ";
	}

	return 0;
}
