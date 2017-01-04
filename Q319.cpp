// solution one, timeout
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int res = 1;
        for(int i = 2; i <= n; i++)
        {
            int factors = 0;
            for(int j = 1; j <= i; j++)
            {
                if(i % j == 0)
                    factors++;
            }
            if(factors % 2 != 0)
                res++;
        }
        return res;
    }
};
// solution two, timeout
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, 0);
        int res = 0;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(dp[i] == 0)
            {
                int factors = 0;
                for(int j = 1; j <= i; j++)
                {
                    if(i % j == 0)
                        factors++;
                }
                dp[i] = factors;
                long long tmp = i;
                tmp = tmp * i;
                while(tmp <= n)
                {
                    dp[tmp] = dp[tmp / i] + 1;
                    tmp = tmp * i;
                }
            }
            else continue;
        }
        for(int i = 0; i < dp.size(); i++)
            if(dp[i] % 2 != 0)
                res++;
        return res;
    }
};
// solution three, "The number of one number's factor is odd if and only if it is a perfect square!!!!!!"
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
