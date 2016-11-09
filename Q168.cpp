class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0) return "";
        string res;
        while(n > 0)
        {
            if(n % 26 != 0)
                res.push_back(n % 26 + 'A' - 1);
            else
            {
                res.push_back('Z');
                n--;
            }
            n = n / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
