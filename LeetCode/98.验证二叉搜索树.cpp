/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月23日 星期一 12:06:50
 *    @Filename: 98.验证二叉搜索树.cpp
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

// 法一：
// 第一个点可以取的范围在-INF 到 INF
// 然后递归判断每个点是否在范围内
// 法二：
// 判断中序遍历是否严格单调递增

// v可能是INT_MIN,-1会爆int，所以用long long和1ll
bool dfs(TreeNode* root, long long Left, long long Right) { 
    if (!root) return true;
    int v = root->val;
    if (v < Left || v > Right) return false;
    
    return dfs(root->left, Left, v - 1ll) && dfs(root->right, v + 1ll, Right);
}

class Solution {
public:    
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> vec;

// 中序遍历
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vec.clear(); // 清空初始vector
        inorder(root);
        for (int i = 1;i < vec.size(); i ++) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        
        return true;
    }
};