class Solution {
   
public:
    double ans(int i,int j,int poured,vector<vector<double>> &dp){
        if(i<0||j<0||i<j)return 0.0;
        if(i==0&&j==0) return poured;
        if(dp[i][j]!=-1) return dp[i][j];
        double a=max(0.0,(ans(i-1,j-1,poured,dp)-1)/2);
        double b=max(0.0,(ans(i-1,j,poured,dp)-1)/2);
        return dp[i][j]=a+b;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double> (query_row+1,0.0));
        dp[0][0]=poured;
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){
                dp[i+1][j]+=max(0.0,(dp[i][j]-1)/2);
                dp[i+1][j+1]+=max(0.0,(dp[i][j]-1)/2);
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};
