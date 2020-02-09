/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月3日 下午01:18:39
 *    @Filename: 201.数字范围按位与.cpp
 */

/*  ====算法分析====
    按位与&
    假设n比m大 m到n个数一起作&运算
    n: 1111110
    m: 1110111
    /从高位开始看，只要第一次出现两个数位数不一样，则从这个位置开始后面一定都是0（因为一定会进位）
    n: 111 1110
    m: 111 0111
    m和n之间一定会有111 1000，则这三个数作&运算就得到1110000
    所以答案就是m和n从高位开始，连续相同的位数构成的数
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            k ++;
        }      

        return m << k;
    }
};