//I think it is a bad question, I still do not understand what doest 1,2,2 means.
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
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> tovisit;
        set<UndirectedGraphNode*> visited;
        tovisit.push(node);
        while(!tovisit.empty())
        {
            int s = tovisit.size();
            int cur = 0;
            while(cur < s)
            {
                cur++;
                UndirectedGraphNode* tmp = tovisit.front();
                tovisit.pop();
                visited.insert(tmp);
                if(m.find(tmp) == m.end()) // If tmp is not cloned, we cloned tmp
                {
                    UndirectedGraphNode* n = new UndirectedGraphNode(node->label);
                    m[tmp] = n;
                }
                for(auto a : tmp->neighbors)
                {
                    if(visited.find(a) == visited.end() && m.find(a) == m.end())
                        tovisit.push(a);
                    if(a->label == tmp->label)
                        m[tmp]->neighbors.push_back(m[tmp]);
                    else if(m.find(a) != m.end() && a->label != tmp->label)
                        m[tmp]->neighbors.push_back(m[a]);
                    else if(m.find(a) == m.end() && a->label != tmp->label)
                    {
                        UndirectedGraphNode* p = new UndirectedGraphNode(a->label);
                        m.insert({a, p});
                        m[tmp]->neighbors.push_back(p);
                    }
                }
            }
        }
        return m[node];
    }
};
