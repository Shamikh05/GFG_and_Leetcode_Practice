class Solution {
private:
    int computeMinCoins(vector<int>& nums, int n, int amount, vector<int> &dp) {
        
        if(amount==0) {
            return 0;
        }
        
        if(dp[amount] != -1) {
            return dp[amount];
        }
        
        int coins = INT_MAX;
        
        for(int i=0;i<n;++i) {
            
            if(amount >= nums[i]) {
                coins = min(coins, computeMinCoins(nums, n, amount-nums[i], dp));
            }
        }
        
        if(coins==INT_MAX) 
            return dp[amount] = coins;
        
        return dp[amount] = 1 + coins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<int> dp(amount+1, -1);
        
        int ans = computeMinCoins(coins, n, amount, dp);
        
        return ans==INT_MAX ? -1 : ans;
    }
};