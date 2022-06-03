class Solution {
private:
    int compute(int s, int e, vector<int>& cuts, vector<vector<int> > &dp) {
        
        if(s > e) return 0;
        
        if(dp[s][e] != -1) return dp[s][e];
        
        int minCost = INT_MAX;
        
        for(int i=s;i<=e;++i) {
            
            int cost = compute(s, i-1, cuts, dp) + compute(i+1, e, cuts, dp);
            
            minCost = min(minCost, cost);
        }
        
        return dp[s][e] = minCost + cuts[e+1] - cuts[s-1];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        
        int len = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int> > dp(len+1, vector<int>(len+1, -1));
        
        int s = 1;
        int e = len;
        
        return compute(s, e, cuts, dp);
    }
};