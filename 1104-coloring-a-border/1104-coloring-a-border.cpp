class Solution {
    int m;
    int n;
    vector<vector<int>> direction={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void dfs(int i,int j,vector<vector<int>> &grid,int color,vector<vector<bool>> &visited){
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
        visited[i][j]=true;
        int flag=0;
        for(auto &dir: direction){
            int i2=i+dir[0];
            int j2=j+dir[1];
            if(i2>=0&&j2>=0&&i2<m&&j2<n){
               if(grid[i][j]!=grid[i2][j2]){
                   flag=1;
               }
            }
            else{
                flag=1;
            }
        }
        for(auto &dir: direction){
            int i2=i+dir[0];
            int j2=j+dir[1];
            if(i2>=0&&j2>=0&&i2<m&&j2<n){
               if(grid[i][j]==grid[i2][j2]&&visited[i2][j2]==false){
                   dfs(i2,j2,grid,color,visited);
               }
            }

        }
        if(flag==1) grid[i][j]=color;
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(row,col,grid,color,visited);
        return grid;
    }
};