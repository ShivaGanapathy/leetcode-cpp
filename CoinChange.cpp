class Solution {
// O(n) time (where n is amount size)
// O(n) space
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < amount+1; i++) {
            for(int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }

        

        return dp[amount] > amount ? -1 : dp[amount];


        

    } 
};
