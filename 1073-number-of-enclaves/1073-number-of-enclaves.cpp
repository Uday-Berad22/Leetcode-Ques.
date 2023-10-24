class Solution {
     vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
  public:
    void BFS(int i,int j,vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        mat[i][j]=0;
        while(!q.empty()){
            pair<int,int> p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            for(auto &dir: directions)
            {
                int xx=x+dir[0];
                int yy=y+dir[1];
                if(xx<n&&yy<m&&xx>=0&&yy>=0&&mat[xx][yy]==1)
                {
                    q.push({xx,yy});
                    mat[xx][yy]=0;
                }
            } 
        }      
    }
    int numEnclaves(vector<vector<int>> &mat) {
        // Code here
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]==1)
            BFS(i,0,mat);
            if(mat[i][m-1]==1)
            BFS(i,m-1,mat);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==1)
            BFS(0,i,mat);
            if(mat[n-1][i]==1)
            BFS(n-1,i,mat);
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