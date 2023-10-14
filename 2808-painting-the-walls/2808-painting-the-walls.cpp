class Solution {
public:
    int fun(int i,int timetaken,int n,int taken,vector<int> &time,vector<vector<int>> &dp,vector<int> &cost){
        if(i>=n ) { if(taken+timetaken>=n)return 0;return 9000000000;}
        if(dp[i][timetaken+taken]!=-1) return dp[i][timetaken+taken];
        if(timetaken>=n-taken){
            return 0;
        }
        int x=fun(i+1,timetaken,n,taken,time,dp,cost);
        int y=fun(i+1,timetaken+time[i],n,taken+1,time,dp,cost)+cost[i];
        return dp[i][timetaken+taken]=min(x,y);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int> (1002,-1));
        int n=cost.size();
        return fun(0,0,n,0,time,dp,cost);
    }
};