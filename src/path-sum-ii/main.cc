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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return ans;
        }
        vector<int> store;
        pathSum(root, sum, store);
        return ans;
    }
private:
    void pathSum(TreeNode *root, int sum, vector<int> &store) 
    {
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                store.push_back(root->val);
                ans.push_back(store);
                store.pop_back();
            }
            return;
        }
        store.push_back(root->val);
        if (root->left != NULL)
            pathSum(root->left, sum - root->val, store);
        if (root->right != NULL)
            pathSum(root->right, sum - root->val, store);
        store.pop_back();
    }

    vector<vector<int> > ans;
};
