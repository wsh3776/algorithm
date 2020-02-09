/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 2020年1月16日 星期四 16:26:37
// 用队列，每次记下当前层有len个结点，然后遍历这len个点
class Solution {
public:
    static const int N =  1e4;
    TreeNode *q[N];
    int hh = 0, tt = 0;
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return {};
        q[tt ++] = root;
        while(hh < tt) {
            int len = tt - hh; // 当前层的结点个数
            vector <int> tmp;
            for(int i = 0; i < len; i ++) {
                auto t = q[hh];
                tmp.push_back(q[hh]->val);
                hh ++;
                if (t->left) q[tt ++] = t->left;
                if (t->right) q[tt ++] = t->right;
            }
            res.push_back(tmp);
        }
        return res;
    }
};