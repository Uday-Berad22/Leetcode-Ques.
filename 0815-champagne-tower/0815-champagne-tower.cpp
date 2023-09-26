class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1);
        dp[0].resize(1,0);
        dp[0][0]=poured;
        for(int i=0;i<query_row;i++){
            dp[i+1].resize(i+2,0);
            for(int j=0;j<=i;j++){
                dp[i+1][j]+=max(0.0,(dp[i][j]-1)/2);
                dp[i+1][j+1]+=max(0.0,(dp[i][j]-1)/2);
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};
