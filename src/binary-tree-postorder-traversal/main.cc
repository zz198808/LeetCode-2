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
        TreeNode *node;
        int counter;
        
        State(TreeNode *n): node(n), counter(0) {
            
        }
    };
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        
        stack<State *> sta;
        push(sta, root);
        
        while (!sta.empty()) {
            State *p = sta.top();
            if (p->counter == 0) {
                if (p->node->left != NULL) {
                    push(sta, p->node->left);
                }
                p->counter++;
            } else if (p->counter == 1) {
                if (p->node->right != NULL) {
                    push(sta, p->node->right);
                }
                p->counter++;
            } else {
                ans.push_back(p->node->val);
                pop(sta);
            }
        }
        
        return ans;
        
    }
private:
    void push(stack<State *> &sta, TreeNode *node) 
    {
        sta.push(new State(node));    
    }
    
    void pop(stack<State *> &sta) 
    {
        State *p = sta.top();
        delete p;
        sta.pop();
    }
    
    
};