class Solution {
int m;
    int n;
    vector<vector<int>> direction={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        if(i<0||j<0||i>=m||j>=n){
            return 0;
        }
        visited[i][j]=true;
        int count=0;
        for(auto &dir: direction){
            int i2=i+dir[0];
            int j2=j+dir[1];
            if(i2>=0&&j2>=0&&i2<m&&j2<n){
               if(grid[i][j]!=grid[i2][j2]){
                  count++;
               }
            }
            else{
                count++;
            }
        }
        int ans=0;
        for(auto &dir: direction){
            int i2=i+dir[0];
            int j2=j+dir[1];
            if(i2>=0&&j2>=0&&i2<m&&j2<n){
               if(grid[i][j]==grid[i2][j2]&&visited[i2][j2]==false){
                   ans+=dfs(i2,j2,grid,visited);
               }
            }

        }
        return ans+count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                { 
                    return dfs(i,j,grid,visited);
                }
            }
        }
        return 0;
    }
};