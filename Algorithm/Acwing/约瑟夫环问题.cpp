// 2019年12月22日 星期日 16:30:12
// 约瑟夫问题
// f(n, m)表示初始是n个数，每次隔m个，最后剩余的数
// 从0开始每+m 删除一个，然后从删除的位置+m在算

//   0,         m-2, m-1, m, m+1,     ,  n-2, n-1
// n-m,         n-2,  X , 0,   1,     ,n-m-2, n-m-1
// f(n-1,m)的结果做个映射得到f(n,m)的结果
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n == 1) return 0;
        else return (lastRemaining(n - 1, m) + m) % n;
    }
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

