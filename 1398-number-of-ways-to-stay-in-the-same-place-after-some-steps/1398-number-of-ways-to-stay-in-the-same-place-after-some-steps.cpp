class Solution {
    int M=1e9+7;
public:
    int fun(int steps,int i,int arrlen,vector<vector<int>> &dp){
        if(i==0&&steps==0){
            return 1;
        }
        if(steps==0||i>=arrlen||i<0){
            return 0;
        }
        if(dp[steps][i]!=-1) return dp[steps][i];
        int a=fun(steps-1,i+1,arrlen,dp);
        int b=fun(steps-1,i-1,arrlen,dp);
        int c=fun(steps-1,i,arrlen,dp);
        return dp[steps][i]=((a+b)%M+c)%M;
    }
    int numWays(int steps, int arrLen) {
        int x=min(steps,arrLen);
        vector<vector<int>> dp(steps+1,vector<int> (x+1,-1));
        return fun(steps,0,arrLen,dp);
    }
};