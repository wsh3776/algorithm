// 小游戏 暴力 40% 32768K 是 800万吗
#include <iostream>

using namespace std;

const int MAX = 1010;

int Q[MAX], Li[MAX];

int main() {
	#ifdef ONLINE_JUDGE
	#else
	freopen("in.txt","r",stdin);
	#endif
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i ++) {
        cin >> Q[i];
    }
    
    for (int i = 0; i < N; i ++) {
        cin >> Li[i];
    }

    int res = 0;
    for (int i = 0; i < N; i ++) {
        int mark = Li[i];
        for (int j = i + 2; j < N; j += 2) {
            if (Li[j] == mark) {
                res = (res + (Q[i] + Q[j]) * (i + 2 + j)) % 10007;
                //cout << res << endl;
            }
        }
    }

    cout << res << endl;

    return 0;
}