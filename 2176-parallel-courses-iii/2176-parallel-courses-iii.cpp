class Solution {
public:
    vector<int> dp,out;
    vector<vector<int>> adj;
    int dfs(int u,vector<int> &time){
        if(dp[u]!=-1)
            return dp[u];
        int res=time[u-1];
        for(auto &v:adj[u])
            res=max(res,time[u-1]+dfs(v,time));
        return dp[u]=res;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        dp.resize(n+1,-1);
        adj.resize(n+1);
        for(auto &e:relations){
            adj[e[1]].push_back(e[0]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dfs(i,time));
        return ans;
    }
};