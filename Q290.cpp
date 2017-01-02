class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,vector<int>> m1;
        map<string,vector<int>> m2;
        for(int i = 0; i < pattern.size(); i++)
            m1[pattern[i]].push_back(i);
        vector<string> s;
        int cur = 0;
        int n = str.size();
        for(int i = 0; i < n; i++)
        {
            if(str[i] == ' ')
            {
                s.push_back(str.substr(cur, i - cur));
                cur = i + 1;
            }
            else if(i == n - 1)
                s.push_back(str.substr(cur, i - cur + 1));
        }
        for(int i = 0; i < s.size(); i++)
            m2[s[i]].push_back(i);
        if(pattern.size() != s.size()) return false;
        if(m1.size() != m2.size()) return false;
        for(auto i : m1)
        {
            string tmp = s[i.second[0]];
            for(int j = 1; j < i.second.size(); j++)
            {
                if(s[i.second[j]] != tmp)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// use istringstream
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,vector<int>> m1;
        map<string,vector<int>> m2;
        for(int i = 0; i < pattern.size(); i++)
            m1[pattern[i]].push_back(i);
        vector<string> s;
        int cur = 0;
        istringstream st(str);
        string temp;
        while(st >> temp)
            s.push_back(temp);
        for(int i = 0; i < s.size(); i++)
            m2[s[i]].push_back(i);
        if(pattern.size() != s.size()) return false;
        if(m1.size() != m2.size()) return false;
        for(auto i : m1)
        {
            string tmp = s[i.second[0]];
            for(int j = 1; j < i.second.size(); j++)
            {
                if(s[i.second[j]] != tmp)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
