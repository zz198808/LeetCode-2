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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        
        unordered_map<int, int> pos;
        
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }
        
        return buildTree(pos, postorder, 0, 0, inorder.size());
    }
    
private:
    TreeNode *buildTree(unordered_map<int, int> &pos, vector<int> &postorder, int a, int b, int n) {
        if (n == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[b + n - 1]);
        int i = pos[root->val];
        root->left = buildTree(pos, postorder, a, b, i - a);
        root->right = buildTree(pos, postorder, i + 1, b + i - a, n - (i - a) - 1);
        return root;
    }
    
};
