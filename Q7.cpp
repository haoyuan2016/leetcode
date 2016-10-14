class Solution {
public:
    int reverse(int x) {
        bool negative_flag = false;
        if(x < 0)
        {
            negative_flag = true;
            x = -x;
        }
        long res = 0;
        while(x > 0)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        else
            return negative_flag? -1 * res : res;
    }
};
