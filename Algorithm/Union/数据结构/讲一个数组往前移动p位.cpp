#include <iostream>

using namespace std;

int f[1000];

void Reverse(int l, int r) {
	for (int i = l, j = r - 1; i <= j; i ++, j --) {
		swap(f[i], f[j]);
	}
}

int main() {
	#ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif

	int n, k;
	cin >> n >> k;

	for (int i = 0 ; i < n; i ++) {
		cin >> f[i];
	}

	Reverse(0, k);
	Reverse(k, n);
	Reverse(0, n);

	for (int i = 0; i < n; i ++) {
		cout << f[i] << " ";
	}
	cout << endl;

	return 0;
}

	