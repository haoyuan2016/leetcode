class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0)
            return res;
        res = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            if(res == strs[i].substr(0, res.size()))
                continue;
            else
            {
                while(res.size() > 0)
                {
                    res.pop_back();
                    if(res == strs[i].substr(0,res.size()))
                        break;
                }
                if(res.size() == 0)
                    return "";
            }
        }
        return res;
    }
};
// note: for string in c++, it is not s.pop() but s.pop_back()
