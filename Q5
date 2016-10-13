class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(i >= 1 && i < s.length() - 1 && s[i - 1] == s[i + 1])
            {
                int len = 1;
                while(i - len >= 0 && i + len < s.length() && s[i - len] == s[i + len])
                    len++;
                string tmp = s.substr(i - len + 1, 2 * len - 1);
                res = res.length() > tmp.length()? res : tmp;
            }
            if(i < s.length() - 1 && s[i] == s[i + 1])
            {
                int len = 1;
                while(i - len >= 0 && i + len + 1 < s.length() && s[i - len] == s[i + len + 1])
                    len++;
                string tmp = s.substr(i - len + 1, 2 * len);
                res = res.length() > tmp.length()? res : tmp;
            }
        }
        return res.empty()? s.substr(0,1) : res;
    }
};

// 1) Note that palindromic [pælɪn'drɒmɪk]
// 2) when we use substr(), the second is the length, but not the index of the end!!
