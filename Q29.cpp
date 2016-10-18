class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)? 1 : -1;
        long long did = labs(dividend), div = labs(divisor);
        int res = 0;
        while(did >= div)
        {
            long long tmp = div;
            long long mul = 1;
            while(did >= tmp)
            {
                tmp = tmp << 1;
                mul = mul << 1;
            }
            res += mul >> 1;
            did = did - (tmp >> 1);
        }
        return res * sign;
    }
};
// Really tricky question. We need to consider two special cases 1) divisor == 0 2) dividend = INT_MIN and divisor == -1 
// We use labs instead of abs, because abs return int but l abs return long int.
// abs => int, labs => long int, llabs => long long abs.
