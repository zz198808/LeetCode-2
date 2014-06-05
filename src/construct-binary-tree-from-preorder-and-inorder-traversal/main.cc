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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> pos;
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }
        return buildTree(preorder, pos, 0, 0, inorder.size());
    }
private:

    TreeNode *buildTree(vector<int> &preorder, unordered_map<int, int> &pos, int a, int b, int n)
    {
        if (n == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[a]);
        int i = pos[root->val];
        root->left = buildTree(preorder, pos, a + 1, b, i - b);
        root->right = buildTree(preorder, pos, a + 1 + (i - b), i + 1, n - (i - b) - 1);
        return root;
    }
};
