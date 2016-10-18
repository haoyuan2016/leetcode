class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int m = needle.length();
        int n = haystack.length();
        for(int i = 0; i <= n - m; i++)
        {
            if(haystack.substr(i, m) == needle)
                return i;
        }
        return -1;
    }
};
