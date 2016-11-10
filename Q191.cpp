class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cur = 0;
        int res;
        while(cur < 32)
        {
            if(n & 1 == 1)
                res++;
            n = n >> 1;
            cur++;
        }
        return res;
    }
};
