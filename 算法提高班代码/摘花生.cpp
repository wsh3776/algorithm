#include <iostream>
#include <cstdio>

using namespace std;

const int N = 110;

int v[N][N], f[N][N];

int main() {
	#ifdef ONLINE_JUDGE
	#else
	    freopen("in.txt","r",stdin);
	    //freopen("out.txt","w",stdout);
	#endif
	

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				cin >> v[i][j]; 
			}
		}

		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + v[i][j]; 
			}
		}

		cout << f[n][m] << endl;
	}


	return 0;
}