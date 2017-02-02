class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto i : nums)
            m[i]++; 
        priority_queue<pair<int, int>> q;
        for(auto i : m)
        {
            q.push(make_pair(i.second, i.first));
        }
        vector<int> res;
        while(k > 0)
        {
            k--;
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
