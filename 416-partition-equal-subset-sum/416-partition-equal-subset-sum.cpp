class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int totalArrSum = 0;
        
        for(int num : nums) {
            totalArrSum += num;
        }
        
        if(totalArrSum & 1) {
            return false;
        }
        
        int target = totalArrSum / 2;
        
        vector<vector<bool> > dp(n, vector<bool>(target+1, 0));
        
        for(int i=0;i<n;++i) {
            
            for(int j=0;j<=target;++j) {
                
                if(i==0 and j==nums[i]) {
                    dp[i][j] = true;
                } 
                else if(j==0) {
                    dp[i][j] = true;
                }
                else if(i and j) {
                    
                    bool take = false;
                    bool notTake = dp[i-1][j];
                    
                    if(j >= nums[i]) {
                        take = dp[i-1][j-nums[i]];
                    }
                    
                    dp[i][j] = (take | notTake);   
                }
            }
        }
        
        return dp[n-1][target];
    }
};