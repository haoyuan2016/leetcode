//Solution one
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        reverse(s.begin(), s.end());
        int tmp = s.find_first_not_of(' ');
        if(tmp == string::npos)
            return 0;
        for(int i = tmp; i < s.length(); i++)
        {
            if(s[i] == ' ')
                return i - tmp;
            if(i == s.length() - 1)
                return s.length() - tmp;
        }
        return s.length();
    }
};
// Also learn to use s.find_first_of( ).
// If the target is not found, return string::npos;
