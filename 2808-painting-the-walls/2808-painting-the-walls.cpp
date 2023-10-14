class Solution {
public:
    int fun(int i,int timetaken,int n,int taken,vector<int> &time,vector<vector<int>> &dp,vector<int> &cost){
        if(taken<=0) return 0;
        if(i>=n ) { return 9000000000;}
        if(dp[i][taken]!=-1) return dp[i][taken];
        int x=fun(i+1,timetaken,n,taken,time,dp,cost);
        int y=fun(i+1,timetaken+time[i],n,taken-1-time[i],time,dp,cost)+cost[i];
        return dp[i][taken]=min(x,y);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int> (1002,-1));
        int n=cost.size();
        return fun(0,0,n,n,time,dp,cost);
    }
};