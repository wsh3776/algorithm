/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月22日 星期日 00:23:24
 *    @Filename: 765.情侣牵手（并查集）.cpp
 */

/*  ====算法分析====
    并查集 
    1.首先初始状态把这N对情侣分别构成一个连通块
    2.考虑k对情侣相互错开的情况，他们形成一个环，可以知道需k-1次交换使排列正确
    3.这样相互错开的情况，分别构成连通块，最后用N - 连通块个数即为答案
    例如：0，1|2，3|... |2N-2,2N-1
    |0 3| ... |7 2|...|6 1| 看相对顺序，可以发现这三对构成一个环，只需2次交换
    同理还有其他类型的环构成连通块
*/

const int N = 80;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();

        // 初始化p[x]数组
        for (int i = 0; i < n; i += 2) {
            p[i + 1] = i;
            p[i] = i;   
        }

        // |0 3| ... |7 2|...|6 1| 合并0，3   7，2  6，1 最终这两个人到同一连通块
        for (int i = 0; i < n; i += 2) {
            p[find(row[i + 1])] = find(row[i]);  
        }

        int res = n / 2;
        for (int i = 0; i <= n; i ++) {
            if (p[i] == i) res --;
        }

        return res;
    }
};