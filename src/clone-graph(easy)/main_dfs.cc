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
        s2t[node] = new UndirectedGraphNode(node->label);
        Dfs(node);
        return s2t[node];
    }
private:
    void Dfs(UndirectedGraphNode *u)
    {
        for (int i = 0; i < u->neighbors.size(); i++) {
            UndirectedGraphNode *v = u->neighbors[i];
            if (s2t.find(v) == s2t.end()) {
                s2t[v] = new UndirectedGraphNode(v->label);
                s2t[u]->neighbors.push_back(s2t[v]);
                Dfs(v);
            } else {
                s2t[u]->neighbors.push_back(s2t[v]);
            }
        }
    }
    
    map<UndirectedGraphNode *, UndirectedGraphNode *> s2t;
};
