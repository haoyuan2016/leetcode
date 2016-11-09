class Solution {
public:
    int trailingZeroes(int n) {
        // return n / 5 + n / 25 + n / 125 + n / .... 
        long t = 1;
        int res = 0;
        while(n > t)
        {
            t = t * 5;
            res += n / t;
        }
        return res;
    }
};
