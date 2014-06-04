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
    int maxPathSum(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        ans = root->val;
        Dfs(root);
        
        return ans;
        
    }
private:
    int Dfs(TreeNode *root) {
        if (NULL == root)
            return 0;
            
        int l = Dfs(root->left);
        int r = Dfs(root->right);
        int maxv = max(max(0, max(l, r) + root->val), root->val);
        
        ans = max(max(max(ans, root->val), root->val + max(l, r)), root->val + l + r);
        return maxv;
        
    }
    
    int ans;
};
