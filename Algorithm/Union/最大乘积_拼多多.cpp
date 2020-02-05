// 2020年2月2日 星期日 12:37:55
// 算法：在无序数组中，找出最大的三个数，和最小的两个数 时间复杂度O(n)

#include <iostream>

using namespace std;

const int INF = 2e9;

int main() {
    int n, t;
    cin >> n;

    // 开int会超数据范围，所以开long long
    long long rmax1 = -INF, rmax2 = -INF, rmax3 = -INF, rmin1 = INF, rmin2 = INF;

    for (int i = 0; i < n; i ++) {
        cin >> t;

        // rmax1更新后，那么rmax2值为原rmax1，rmax3为原rmax2
        // 如果有相同的数，默认在次序前面的"大"  如：[1 4 5 5 3]
        if (t > rmax1) { 
            rmax3 = rmax2;
            rmax2 = rmax1;
            rmax1 = t;
        } else if (t > rmax2) {
            rmax3 = rmax2;
            rmax2 = t;
        } else if (t > rmax3) {
            rmax3 = t;
        }

        if (t < rmin1) {
            rmin2 = rmin1;
            rmin1 = t;
        } else if (t < rmin2) {
            rmin2 = t;
        }
    }
   
    cout << max(rmax1 * 1ll * rmax2 * rmax3, rmax1 * 1ll * rmin2 * rmin1) << endl;

    return 0;
}
