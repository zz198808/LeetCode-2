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
    struct State {
        TreeNode* node;
        int counter;
        
        State(TreeNode* n): node(n), counter(0)
        {
            
        }
    };
    
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<State*> sta;
        push(sta, root);
        while (!sta.empty()) {
            State* p = sta.top();
            if (0 == p->counter) {
                ans.push_back(p->node->val);
                p->counter++;
            } else if (1 == p->counter) {
                if (p->node->left != NULL) {
                    push(sta, p->node->left);
                }
                p->counter++;
            } else if (2 == p->counter) {
                if (p->node->right != NULL) {
                    push(sta, p->node->right);
                }
                p->counter++;
            } else {
                pop(sta);
            }
        }
        return ans;
    }
private:
    void push(stack<State*> &sta, TreeNode* node)
    {
        sta.push(new State(node));
    }
    
    void pop(stack<State*> &sta)
    {
        delete sta.top();
        sta.pop();
    }
};