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
        vector<int> dp(n+1,-1);
        return  min(fun(0,dp,cost),fun(1,dp,cost));
    }
};