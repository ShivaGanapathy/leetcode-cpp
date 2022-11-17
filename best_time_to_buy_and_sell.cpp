class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lp = 0;
        int profit = 0;
        int max_profit = 0;
    
        for (int i = 0; i < prices.size(); i++) {
            profit = prices[i] - prices[lp];
            if (profit > max_profit) {
                max_profit = profit;
            }
            if (profit < 0) {
                lp = i;
            }
        }
        
        return max_profit;
        
    }
};
