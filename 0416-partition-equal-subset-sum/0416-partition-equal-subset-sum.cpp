class Solution {
public:
     bool fun(int i,int Taken,int NotTaken,int N,vector<int> &arr,vector<vector<int>> &dp){
        if(i==N) {
            if(Taken ==NotTaken) return true;
            return false;
        }
        if(dp[i][Taken]!=-1) return dp[i][Taken];
        return dp[i][Taken]=fun(i+1,Taken,NotTaken+arr[i],N,arr,dp)||fun(i+1,Taken+arr[i],NotTaken,N,arr,dp);
    }
    bool canPartition(vector<int>& arr) {
        int N=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(N+1,vector<int> (sum+1,-1));
        return fun(0,0,0,N,arr,dp);
    }
};