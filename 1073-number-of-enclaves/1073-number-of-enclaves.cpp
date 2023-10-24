class Solution {
     vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
  public:
    void DFS(int x,int y,vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        mat[x][y]=0;
        for(auto &dir: directions)
        {
            int xx=x+dir[0];
            int yy=y+dir[1];
            if(xx<n&&yy<m&&xx>=0&&yy>=0&&mat[xx][yy]==1)
                DFS(xx,yy,mat);
        }       
    }
    int numEnclaves(vector<vector<int>> &mat) {
        // Code here
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(mat[i][j]==1)
                    DFS(i,j,mat);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                   count++;
                }
            }
        }
        return count;
    }
};