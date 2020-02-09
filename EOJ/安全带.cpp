#include <set>
#include <iostream>

using namespace std;

int a[10005];

int main() {
    #ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
    
    set <pair<int, int> > hash;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i]; 
    }

    long long res = 0;
    for (int i = 0; i <  n - 1; i ++ ) {
        res += a[i] * a[i + 1];
        hash.insert({i, i + 1});
    }

    res += a[0] * a[n - 1]; 
    hash.insert({0, n - 1});

    int t = 0;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        if (t) {
            for (int j  = 0; j < n; j ++) {
                int t = i, b = j;
                if (t > b) swap(t, b);
                if (j != i && hash.find({t, b}) ==  hash.end()){ 
                    res += a[i] * a[j]; 
                    if (i > j) hash.insert({j, i});
                    else hash.insert({i, j});
            }
            
        }
    }

    }
        cout << res << endl;


    return 0;

    }

