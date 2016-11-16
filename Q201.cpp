// My solution
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int tmp = n;
        int len = 0;
        int res = 0;
        while(tmp > 0)
        {
            tmp = tmp >> 1;
            len++;
        }
        int dis = n - m;
        int cur = pow(2, len - 1);
        if(dis < cur && m / cur % 2 != 0 && n / cur % 2 != 0)
            res += 1;
        while(len > 1)
        {
            len--;
            res = res << 1;
            int cur = pow(2, len - 1);
            if(dis < cur && m / cur % 2 != 0 && n / cur % 2 != 0)
                res += 1;
        }
        return res;
    }
};
// see http://www.cnblogs.com/grandyang/p/4431646.html
