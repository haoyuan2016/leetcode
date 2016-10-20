// Method one. Time out
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;
        res.push_back(vector<string>{strs[0]});
        for(int i = 1; i < strs.size(); i++)
        {
            bool flag = false;
            for(int j = 0; j < res.size(); j++)
            {
                if(isAnagrams(res[j][0], strs[i]))
                {
                    res[j].push_back(strs[i]);
                    flag = true;
                }
            }
            if(!flag) res.push_back(vector<string>{strs[i]});
        }
        return res;
    }
    bool isAnagrams(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
// Second method, we use a map<string, int> to store the sorted string and the index in res.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        int cur = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(m.find(tmp) == m.end())
            {
                m.insert({tmp, cur});
                res.push_back(vector<string>{strs[i]});
                cur++;
            }
            else
                res[m[tmp]].push_back(strs[i]);
        }
        return res;
    }
};
