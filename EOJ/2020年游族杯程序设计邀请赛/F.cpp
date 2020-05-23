// 这里有两个文件后缀为.eoj，这点没想到，存到 map 里要把整个路径存进去
// 2
// /cuber.eoj/qq.eoj
// /cuber.eoj/cuber.eoj

#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

unordered_map<string, LL> dirs, files;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    LL n;
    cin >> n;
    string s;

    for (LL k = 1; k <= n; k++) {
        cin >> s;
        // cout << s << endl;
        LL sn = s.size();
        // cout << sn << endl;
        for (LL i = 1, j = 1; i < sn; i++) {
            // cout << "dsf " << endl;
            while (j < sn && s[j] != '/')
                j++;
            // cout << j << endl;
            string tmp = s.substr(i, j - i);
            LL t = tmp.size();

            // cout << tmp << endl;
            if (j == sn) {
                if (t > 4 && tmp.substr(t - 4, 4) == ".eoj") {
                    files[s.substr(0, j)]++;
                    // cout << "here: " << tmp << endl;
                }
            } else {
                if (t > 4 && tmp.substr(t - 4, 4) == ".eoj") {
                    dirs[s.substr(0, j)]++;
                }
            }

            i = j;
            j++;
        }
    }

    LL res = 0;
    for (auto file : files) {
        if (!dirs.count(file.first)) {
            // cout << file.first << endl;
            res += file.second;
        }
    }

    cout << res << endl;

    return 0;
}
