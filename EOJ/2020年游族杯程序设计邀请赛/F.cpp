// 思路：其实应该可以用前缀树去做，不过我这里用的是 map 去存，然后判断 file 在不在 dirs 中
// 坑点：目录名和文件名可以相同
// 样例：
// 2
// /cuber.eoj/qq.eoj
// /cuber.eoj/cuber.eoj

#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

unordered_map<string, LL> dirs, files;

int main() {
    LL n;
    cin >> n;
    string s;

    for (LL k = 1; k <= n; k++) {
        cin >> s;

        LL sn = s.size();
        for (LL i = 1, j = 1; i < sn; i++) {
            while (j < sn && s[j] != '/') // 双指针思想
                j++;
            string tmp = s.substr(i, j - i);
            LL t = tmp.size();

            // 把完整路径存到 map 中
            if (j == sn) {
                if (t > 4 && tmp.substr(t - 4, 4) == ".eoj") { // 后四位是否为 .eoj
                    files[s.substr(0, j)]++;
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

    // 看是否有前缀（好像有点像前缀树）
    LL res = 0;
    for (auto file : files) {
        if (!dirs.count(file.first)) {
            res += file.second;
        }
    }

    cout << res << endl;

    return 0;
}
