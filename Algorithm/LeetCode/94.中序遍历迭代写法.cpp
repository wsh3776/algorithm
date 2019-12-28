/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月23日 星期一 13:34:05
 *    @Filename: 94.中序遍历迭代写法.cpp
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历，迭代写法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        auto cur = root;
        while(cur || stk.size()) {
            while(cur) { // 结点非空时，把左侧的点全加到栈,然后倒着遍历
                stk.push(cur);
                cur = cur->left;
            }
            // stk:1 2 4 8
            cur = stk.top();
            stk.pop(); 
            res.push_back(cur->val);
            cur = cur->right; // 遍历该结点的右子树，如果为空，则继续栈
        }
        return res;
    }
};