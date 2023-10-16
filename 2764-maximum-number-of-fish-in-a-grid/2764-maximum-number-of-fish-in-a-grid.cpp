class Solution {
    int m;
    int n;
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int flood_fill_using_dfs(vector<vector<int>> &grid,int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return 0;
        int count=grid[i][j];
        grid[i][j]=0;
        for(auto &dir: directions){
            count+=flood_fill_using_dfs(grid,i+dir[0],j+dir[1]);
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,flood_fill_using_dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};