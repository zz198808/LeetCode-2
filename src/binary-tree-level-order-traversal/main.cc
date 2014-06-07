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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL)
            return ans;
        
        queue<pair<TreeNode *, int> > q;
        
        q.push(make_pair(root, 0));
        
        vector<int> tmp;
        
        while (!q.empty()) {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *root = p.first;
            int level = p.second;
            if (ans.size() < level) {
                ans.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(root->val);
            if (root->left != NULL) {
                q.push(make_pair(root->left, level + 1));
            }
            if (root->right != NULL) {
                q.push(make_pair(root->right, level + 1));
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL)
            return ans;
        
        queue<pair<TreeNode *, int> > q;
        
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *root = p.first;
            int level = p.second;
            if (ans.size() <= level) {
                ans.push_back(vector<int>());
            }
            ans[level].push_back(root->val);
            if (root->left != NULL) {
                q.push(make_pair(root->left, level + 1));
            }
            if (root->right != NULL) {
                q.push(make_pair(root->right, level + 1));
            }
        }
        
        return ans;
    }
};
