class Solution {
public:
    int fun(int i,vector<int> &dp,vector<int> &cost){
        int n=cost.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int x=fun(i+1,dp,cost)+cost[i];
        int y=fun(i+2,dp,cost)+cost[i];
        return dp[i]=min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=min(dp[i+1],dp[i+2])+cost[i];
        }
        return min(dp[0],dp[1]);
    }
};