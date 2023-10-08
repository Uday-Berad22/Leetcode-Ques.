class Solution {
    int M=1e9+7;
public:
    int recur(int i,int n,int m,int length,int max,int k,vector<vector<vector<int> >> &dp){
        if(i==n||length>k){
            if(i==n&&length==k){
                return 1;
            }
            return 0;
        }
        if(dp[i][max][length]!=-1) return dp[i][max][length];
        int ans=0;
        for(int j=1;j<=m;j++){
            if(j<=max)
            ans=(ans+(recur(i+1,n,m,length,max,k,dp))%M)%M;
            else
            ans=(ans+(recur(i+1,n,m,length+1,j,k,dp))%M)%M;
        }
        return dp[i][max][length]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int> >> dp(n+1,vector<vector<int>>  (m+1,vector<int> (k+1,-1)));
        return recur(0,n,m,0,0,k,dp);
    }
};