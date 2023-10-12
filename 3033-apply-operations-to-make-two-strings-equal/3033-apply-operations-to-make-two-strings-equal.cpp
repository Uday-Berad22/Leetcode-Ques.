class Solution {
public:
    int fun(vector<int> &indexarray,int i,int j,int x,vector<vector<int>> &dp){
        if(i>=indexarray.size()||j<0) return 0;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=INT_MAX,b=INT_MAX;
        if(i+1<indexarray.size())a=indexarray[i+1]-indexarray[i]+fun(indexarray,i+2,j,x,dp);
        if(j-1>=0) b=indexarray[j]-indexarray[j-1]+fun(indexarray,i,j-2,x,dp);
        int c=x+fun(indexarray,i+1,j-1,x,dp);
        cout<<a<<" "<<b<<" "<<c<<endl;
        return dp[i][j]=min(min(a,b),c);
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> indexarray;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                indexarray.push_back(i);
            }
        }
        if(indexarray.size()%2!=0) return -1;
        vector<vector<int>> dp(indexarray.size()+1,vector<int> (indexarray.size(),-1));
        return fun(indexarray,0,indexarray.size()-1,x,dp);
    }
};