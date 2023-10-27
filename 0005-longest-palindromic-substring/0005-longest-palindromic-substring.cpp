class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
      vector<vector<bool>> dp(n,vector<bool> (n));
        for(int i=0;i<n;i++){
            int r=0,c=i;
            while(c<n&&r<n){
                if(i==0){
                    dp[r][c]=true;
                }
                else if(i==1){
                    if(s[r]==s[c]){
                        dp[r][c]=true;
                    }
                }
                else{
                    if(s[r]==s[c]){
                        dp[r][c]=dp[r+1][c-1];
                    }
                }
                r++;
                c++;

            }
        }
        int x=0,y=0;
        int diff=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==true){
                 if(abs(i-j)>diff){
                    diff=abs(i-j);
                    x=i;y=j;
                 }
                }
            }
        }
        string ans;
        for(int i=x;i<=y;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};