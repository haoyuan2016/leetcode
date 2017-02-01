class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> m;
        for(int i = 0; i < tickets.size(); i++)
        {
            m[tickets[i].first].insert(tickets[i].second);
        }
        vector<string> res;
        stack<string> s;
        s.push("JFK");
        while(!s.empty())
        {
            string tmp = s.top();
            if(m[tmp].empty())
            {
                res.push_back(tmp);
                s.pop();
            }
            else
            {
                s.push(*m[tmp].begin());
                m[tmp].erase(m[tmp].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
