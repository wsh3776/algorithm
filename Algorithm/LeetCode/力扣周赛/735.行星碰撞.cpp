/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月5日 下午08:29:51
 *    @Filename: 735.行星碰撞.cpp
 */
/*  ====算法分析====
    stack 时间复杂度:O(n), 空间复杂度:O(n)
    在草稿纸上演算一遍，然后分情况讨论即可
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        stack <int> stk;
        vector <int> res;
        // 1 3 -2 -5 2 8
        for (int i = 0; i < n; i ++) {
            int x = asteroids[i];
            if (stk.empty()) stk.push(x);
            else {
                if (stk.top() * x > 0 || x > 0) { // 同号或x为正就加入栈中，因为一定不会相撞
                    stk.push(x);
                } else {
                    while(stk.size() && stk.top() < abs(x) && stk.top() * x < 0) { // 此时x一定小于0，如果栈顶是正的，且比x的重量小，则出栈
                        stk.pop();
                    }

                    // 出了while循环后，只剩三种情况：栈顶为负，栈顶为正但重量比x大，栈顶为正但重量和x相同
                    if (stk.empty() || stk.top() < 0) stk.push(x);
                    else if (stk.top() > abs(x)) continue;
                    else if (stk.top() == abs(x)) stk.pop(); 
                }
            }
        }

        while(stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};