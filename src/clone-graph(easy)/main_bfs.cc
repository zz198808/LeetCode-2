/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        queue<UndirectedGraphNode *>  q;
        map<UndirectedGraphNode *, UndirectedGraphNode *> s2t;
        q.push(node);
        s2t[node] = new UndirectedGraphNode(node->label);
        
        while (!q.empty()) {
            UndirectedGraphNode *u = q.front();
            q.pop();
            for (int i = 0; i < u->neighbors.size(); i++) {
                UndirectedGraphNode *v = u->neighbors[i];
                if (s2t.find(v) == s2t.end()) {
                    q.push(v);
                    s2t[v] = new UndirectedGraphNode(v->label);
                }
                
                s2t[u]->neighbors.push_back(s2t[v]);
                
            }
        }
        return s2t[node];
        
        
    }
};
