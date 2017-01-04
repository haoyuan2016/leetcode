class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	if (n == 1) return vector<int>{0};
	if (n == 2) return vector<int>{edges[0].first, edges[0].second};
	vector<int> res;
	vector<int> degrees(n, 0);
	map<int, vector<int>> m;
	int visited = n;
	for (auto i : edges)
	{
		degrees[i.second]++;
		degrees[i.first]++;
		m[i.first].push_back(i.second);
		m[i.second].push_back(i.first);
	}
	queue<int> q;
	for (int i = 0; i < degrees.size(); i++)
	{
		if (degrees[i] == 1)
		{
			degrees[i]--;
			q.push(i);
		}
	}
	while (!(q.empty()))
	{
		int n = q.size();
		int cur = 0;
		while (cur < n)
		{
			int t = q.front();
			visited--;
			q.pop();
			cur++;
			for (auto i : m[t])
			{
				degrees[i]--;
				if (degrees[i] == 1)
					q.push(i);
			}
		}
		if (visited == 1 || visited == 2)
			break;
	}
	while (!q.empty())
	{
		res.push_back(q.front());
		q.pop();
	}
	return res;
}
};
