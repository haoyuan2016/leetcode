class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return vector<vector<string>>{vector<string>{}};
        vector<vector<string>> res;
        vector<string> holder;
        getPartition(res, holder, s, 0);
        return res;
    }
    void getPartition(vector<vector<string>>& res, vector<string>& holder, string s, int cur){
        if(cur == s.size())
        {
            res.push_back(holder);
            return;
        }
        for(int i = 1; i <= s.substr(cur).size(); i++)
        {
            string tmp = s.substr(cur).substr(0, i);
            if(isPalindrome(tmp))
            {
                holder.push_back(tmp);
                getPartition(res, holder, s, cur + i);
                holder.pop_back();
            }
            else continue;
        }
    }
    bool isPalindrome(string s)
    {
        if(s.empty()) return false;
        int l = 0, r = s.size() - 1;
        while(l < r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
                continue;
            }
            return false;
        }
        return true;
    }
};
