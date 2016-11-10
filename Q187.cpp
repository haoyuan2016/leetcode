class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.empty() || s.size() < 10) return vector<string>{};
        unordered_map<string, int> m;
        vector<string> res;
        int n = s.size();
        string tmp;
        for(int i = 0; i < n - 9; i++)
        {
            tmp = s.substr(i, 10);
            if(m.find(tmp) == m.end())
                m.insert({tmp, 0});
            else
            {   
                m[tmp]++;
                if(m[tmp] == 1)
                    res.push_back(tmp);
            }
        }
        return res;
    }
};
