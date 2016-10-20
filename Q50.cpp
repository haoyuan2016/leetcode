// Note that when we calculate n = -n, we always need to consider that if n == INT_MIN, then overflow. 
// The idea here is like if we calculate 2^32, we need to calculate 32 times directly, but we only need 5 times if we do ((((2^2)^2)^2)^2)^2.
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n < 0)
        {
            if(n == INT_MIN)
            {
                n++;
                n = -n;
                x = 1 / x;
                return x * myPow(x, n);
            }
                
            x = 1 / x;
            n = - n;
        }
        return (n % 2) == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};
