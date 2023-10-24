class Solution {
vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void DFS(int x,int y,vector<vector<char>> &mat,bool &boundary){
        int n=mat.size();
        int m=mat[0].size();
        if(boundary==false){
            mat[x][y]='X';
        }
        else{
            mat[x][y]='-';
        }
        for(auto &dir: directions)
        {
            int xx=x+dir[0];
            int yy=y+dir[1];
            if(xx<n&&yy<m&&xx>=0&&yy>=0&&mat[xx][yy]=='O')
                DFS(xx,yy,mat,boundary);
        }       
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        bool boundary=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(mat[i][j]=='O')
                    DFS(i,j,mat,boundary);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='-'){
                    mat[i][j]='O';
                }
                else if(mat[i][j]=='O')
                    mat[i][j]='X';
            }
        }
    }
};