// Learn to use isalnum, toupper, tolower.
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(!(tolower(s[l]) - 'a' <= 26 && tolower(s[l]) - 'a' >=0) && !(tolower(s[l]) - '0' >=0 && '9' - tolower(s[l]) >= 0))
                l++;
            while(!(tolower(s[r]) - 'a' <= 26 && tolower(s[r]) - 'a' >=0) && !(tolower(s[r]) - '0' >=0 && '9' - tolower(s[r]) >= 0))
                r--;
            if(l >= r)
                return true;
            else if(tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
// See solution with isalmun
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(!isalnum(s[l]))
                l++;
            while(!isalnum(s[r]))
                r--;
            if(l >= r)
                return true;
            else if(tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
