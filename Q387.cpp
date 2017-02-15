// solution one:
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> um;
        for(int i = 0; i < s.size(); i++)
        {
            if(um.find(s[i]) != um.end())
                um[s[i]] = -1;
            else
                um[s[i]] = i;
        }
        int res = INT_MAX;
        for(auto i : um)
        {
            if(i.second < res && i.second >= 0)
                res = i.second;
        }
        return res == INT_MAX ? -1 : res;
    }
};
