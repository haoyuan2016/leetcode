class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        int smallest = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - smallest);
            smallest = min(smallest, prices[i]);
        }
        return profit;
    }
};
