class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        int profit = 0;
        int smallest = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            smallest = min(smallest, prices[i]);
            if(prices[i] - smallest < profit)
            {
                smallest = prices[i];
                res += profit;
                profit = 0;
            }
            else
                profit = prices[i] - smallest;
        }
        return profit + res;
        
    }
};
