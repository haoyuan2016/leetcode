class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = getGraph(numCourses, prerequisites);
        vector<int> indegree = getIndegree(numCourses, graph);
        vector<int> path;
        for(int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for(; j < numCourses; j++)
                if(indegree[j] == 0)
                {
                    indegree[j] = -1;
                    break;
                }
            if(j == numCourses) return vector<int>{};
            path.push_back(j);
            for(auto a : graph[j])
                indegree[a]--;
        }
        return path;
    }
    vector<unordered_set<int>> getGraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        return graph;
    }
    vector<int> getIndegree(int numCourses, vector<unordered_set<int>> graph)
    {
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < graph.size(); i++)
        {
            for(int a : graph[i])
                indegree[a]++;
        }
        return indegree;
    }
};
