// Solution one, not fast enough.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m1, m2;
        for(int i = 0; i < s.size(); i++)
        {
            if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())
            {
                m1.insert({s[i], i});
                m2.insert({t[i], i});
            }
            else if(m1.find(s[i]) != m1.end() && m2.find(t[i]) != m2.end() && m1[s[i]] == m2[t[i]])
                continue;
            else
                return false;
        }
        return true;
    }
};
