// This question is special, instead of using DP solution, we kind of use the markov chain.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> s0(n), s1(n), s2(n);
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[n - 1], s2[n - 1]);
    }
};
