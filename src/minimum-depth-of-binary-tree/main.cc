/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int ans = 1;
        if (root->left == NULL) {
            ans += minDepth(root->right);
        } else if (root->right == NULL) {
            ans += minDepth(root->left);
        } else {
            ans += min(minDepth(root->left), minDepth(root->right));
        }
        
        return ans;
    }
};
