class Solution {
    int m;
    int n;
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    void Flood_fill_using_DFS(vector<vector<char>> &grid,int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0') return;
        grid[i][j]='0';
        for(auto &dir: directions){
            Flood_fill_using_DFS(grid,i+dir[0],j+dir[1]);
        }
        return;
    }
    int numIslands(vector<vector<char>> &grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    Flood_fill_using_DFS(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};