class Solution {
public:
    int maxi(int a,int b,int c){
        return max(max(a,b),c);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        dp[1][1]=nums1[0]*nums2[0];
        for(int i=2;i<=m;i++){
            dp[1][i]=max(dp[1][i-1],nums1[0]*nums2[i-1]);
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=maxi(dp[i-1][j],nums1[i-1]*nums2[j-1],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]);
                if(j==1){
                    continue;
                }
                dp[i][j]=maxi(dp[i-1][j],nums1[i-1]*nums2[j-1],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};