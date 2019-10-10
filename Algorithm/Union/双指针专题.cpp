#include <iostream>

using namespace std;

const int N = 1010;

int a[N];

int main() {
	#ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	// 暴力做法 时间复杂度o(n^2)
	int res = -0x3f3f3f3f;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			res = max(res, a[i] - a[j]);
		}
	}

	// 双指针做法 时间复杂度o(n)
	int res = -0x3f3f3f3f;
	for (int i = 2, j = 1; i <= n; i ++) {
		if (a[i] <= a[j]) {
			j = i;
		} else {
			res = max(res, a[i] - a[j]);
		}
	}

	// 特殊情况，全部递减
	if (res == -0x3f3f3f3f) {
		for (int i = 2; i <= n; i ++) {
			res = max(res, a[i] - a[i - 1]);
		}
	}

	cout << res << endl;

	return 0;
}
