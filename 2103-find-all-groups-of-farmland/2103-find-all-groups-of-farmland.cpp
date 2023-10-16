class Solution {
    int m;
    int n;
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    int Flood_fill_using_DFS(vector<vector<int>> &grid,int i,int j,int &lix,int &liy,int &fi1,int &fi2){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return 0;
        int count=grid[i][j];
        grid[i][j]=0;
        for(auto &dir: directions){
            count+=Flood_fill_using_DFS(grid,i+dir[0],j+dir[1],lix,liy,fi1,fi2);
        }
        if(i+j>lix+liy){
            lix=i;
            liy=j;
        }
        if(fi1+fi2>i+j){
            fi1=i;
            fi2=j;
        }
        return count;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int li1=0,li2=0;
                int fi1=0,fi2=0;
                if(Flood_fill_using_DFS(grid,0,0,li1,li2,fi1,fi2)){
                    ans.push_back({i,j,li1,li2});
                }
            }
        }
    
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int li1=0,li2=0;
                int fi1=i,fi2=j;
                if(Flood_fill_using_DFS(grid,i,j,li1,li2,fi1,fi2)){
                    ans.push_back({fi1,fi2,li1,li2});
                }
            }
        }
        return ans;
    }
};