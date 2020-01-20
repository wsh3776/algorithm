/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 层次遍历，然后对每个结点编号（结构体），每一层记录最小的编号和最大的编号，算出深度
// 此题数据范围比较大，32位整数，故要用double来存
class Solution {
public:
    // 构造指针+编号的结构体
    typedef struct node {
        TreeNode *a;
        double b;
    } node;

    int widthOfBinaryTree(TreeNode *root) {
        queue <node> q;
        q.push({root, 1});
        double res = 1;

        while(q.size()) {
            int len = q.size();
            double mn = DBL_MAX, mx = 0; // DBL_MAX是double的最大值 大约10^308次

            // 对于每一层找到左边界和右边界
            for (int i = 1; i <= len; i ++) {
                auto t = q.front();
                q.pop();
                if (t.a->left) {
                    q.push({t.a->left, 2 * t.b});
                    mn = min(mn, 2 * t.b);
                    mx = max(mx, 2 * t.b);
                }
                if (t.a->right) {
                    q.push({t.a->right, 2 * t.b + 1});
                    mn = min(mn, 2 * t.b + 1);
                    mx = max(mx, 2 * t.b + 1);
                }
            }

            res = max(res, (double)((int)(mx - mn) + 1));
        }

        return (int)res;
    }
};