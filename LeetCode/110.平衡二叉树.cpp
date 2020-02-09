/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月24日 星期二 19:26:00
 *    @Filename: 110.平衡二叉树.cpp
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
class Solution {
public:
    // 求子树的高度
    int height(TreeNode *p) {
        if (!p) return 0;
        return max(height(p->left), height(p->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root) return true; // 如果它是空的，这个子树自然满足平衡二叉树
        if (abs(height(root->left) - height(root->right)) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};