/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月24日 星期二 18:29:11
 *    @Filename: 106.从中序与后序遍历序列构造二叉树.cpp
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

// 后序遍历 postorder = [9,15,7,20,"3"]
// 中序遍历 inorder   = [9,"3",15,20,7]
//     3
//   9  20
//     15 7

// 跟105的做法是相同的

class Solution {
public:
    unordered_map <int, int> hash;

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int p1, int p2, int in1, int in2) {
        // p1后续遍历左端点，p2后续遍历右端点，in1中序遍历左端点，in2中序遍历右端点
        if (p1 > p2) return NULL;

        int val = postorder[p2];
        int key = hash[val];
        int len = key - in1; // 左子树长度
        auto root = new TreeNode(val);
        root->left = dfs(inorder, postorder, p1, p1 + len - 1, in1, key - 1);
        root->right = dfs(inorder, postorder, p1 + len, p2 - 1, key + 1, in2);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++) hash[inorder[i]] = i;
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};


