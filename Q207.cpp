// BFS solution.
// As the name of the course is just interger number, so we can use a vector<unordered_set> to do the adjacent graph. Othersiwe, we need a map
// For the DFS method, we need to check the indegree. We set indegree = -1 if one node is visited.
// Also see wiki on https://en.wikipedia.org/wiki/Topological_sorting
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = getGraph(numCourses, prerequisites);
        vector<int> indegree = getInDegree(numCourses, graph);
        for(int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for(; j < numCourses; j++)
                if(indegree[j] == 0)
                    break;
            if(j == numCourses) return false;
            indegree[j] = -1;
            for(auto a : graph[j])
                indegree[a]--;
        }
        return true;
    }
    
    vector<unordered_set<int>> getGraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        return graph;
    }
    vector<int> getInDegree(int numCourses, vector<unordered_set<int>> graph)
    {
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < graph.size(); i++)
        {
            for(auto a : graph[i])
                indegree[a]++;
        }
        return indegree;
    }
};
