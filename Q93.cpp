// Solution one:
// For string, the argement in insert and erase is not iterator but position. And for both of them, two arguement are needed.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() < 4 || s.length() > 12)
            return res;
        string holder = s;
        helper(res, holder, s, 1);
        return res;
    }
    void helper(vector<string>& res, string& holder, string s, int cur)
    {
        if(holder.length() == s.length() + 3)
        {
            stringstream ss(holder);
            string tmp;
            while(getline(ss, tmp, '.'))
            {
                if(tmp.length() > 1 && tmp[0] == '0') return;
                int a = stoi(tmp);
                if(a > 255 || a < 0)
                    return;
            }
            res.push_back(holder);
            return;
        }
        for(int i = cur; i < holder.length(); i++)
        {
            holder.insert(i, ".");
            helper(res, holder, s, i + 2);
            holder.erase(i, 1);
        }
    }
};
