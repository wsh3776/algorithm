// 按区间左端点排序
// 从前往后遍历区间，并且维护当前[st,ed]区间
// 核心： l > ed，则[st,ed]加入 res，并更新成[l,r]，否则只需更新ed

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n, res;

void merge(vector<PII> &segs) { // segs 必须传引用
    vector<PII> res;

    sort(segs.begin(), segs.end()); // 按左端点从小到大排序

    int st = -2e9, ed = -2e9; // 一开始 st 和 ed 设为负无穷
    for (auto seg : segs) {
        int l = seg.first, r = seg.second;
        if (ed < l) { // 说明第i个区间没有和当前合并的区间有交集
            if (st != -2e9) {
                res.push_back({st, ed});
            }
            st = l, ed = r;
        } else {
            ed = max(ed, r);
        }
    }

    if (st != -2e9) res.push_back({st, ed}); // 加入最后一个合并好的区间

    segs = res;
}

int main() {
    vector<PII> segs;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs); // 用引用返回 segs

    cout << segs.size() << endl;

    return 0;
}