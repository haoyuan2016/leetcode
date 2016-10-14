class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int tmp = x;
        int length_x = 0;
        long long base = 1;
        while(tmp > 0)
        {
            tmp = tmp / 10;
            length_x++;
            base = base * 10;
        }
        base = base / 10;
        int cur = 0;
        int tmp1 = x;
        while(cur < length_x / 2)
        {
            cur++;
            if(tmp1 % 10 == x / base)
            {
                tmp1 = tmp1 / 10;
                x = x - x / base * base;
                base = base / 10;
            }
            else
                return false;
        }
        return true;
    }
};
// note: there shoule be many solutions for this problem. 
// note: -1 is considered to be false.
// note that when we want to change x = 2345 to x = 345, we need to use x - x / base * base where base = 1000.
