// Solution one: use a map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
        {
            if(m.find(s[i]) == m.end())
                m.insert({s[i], 1});
            else
                m[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(m.find(t[i]) == m.end())
                return false;
            else 
                m[t[i]]--;
            if(m[t[i]] < 0)
                return false;
        }
        return true;
    }
};
// Solution two: use sort
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;
    }
};
