/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月24日 星期二 13:34:41
 *    @Filename: 105.从前序与中序遍历序列构造二叉树.cpp
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

// 前序遍历 preorder = [“3”,9,20,15,7]
// 中序遍历 inorder =  [9,“3”,15,20,7]
// "3"根节点，分成了两部分

class Solution {
public:
    unordered_map <int, int> hash;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pre1, int pre2, int in1, int in2) {
        if (pre1 > pre2) return NULL; // 出口必须先写
        int val = preorder[pre1]; // 拿出根节点的val
        auto root = new TreeNode(val); // 创建一个val，NULL，NULL的结点
        

        int k = hash[val];
        int len = k - in1; // 表示先序遍历的长度
        root->left = dfs(preorder, inorder, pre1 + 1, pre1 + 1 + len - 1, in1, k - 1);
        root->right = dfs(preorder, inorder, pre1 + 1 + len, pre2, k + 1, in2);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n  = preorder.size();
        for (int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};