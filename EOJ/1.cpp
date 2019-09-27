#include <iostream>
#include <cstdio>

using namespace std;

class UnionFind {
public:
	vector<int> father;
	UnionFind(int num) {
		for (int i = 0; i < num; i ++) {
			father.push_back(i);
		}
	}

	int Find(int n) {
		if (father[n] == n) return n;
		father[n] = Find(father[n]);
		return father[n];
	}

	void Union(int a, int b) {
		int fa = Find(a);
		int fb = Find(b);
		father[fb] = fa;
	}
};

int main() {
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    cout << "不要强迫症，瞎折腾" << endl;

    return 0;
}
