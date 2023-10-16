class Solution {
public:
    void dfs(vector<vector<bool> > & visited,int i,int j,int &N,int &M,vector<vector<int>>& matrix){
       if((i==N||j==M)||(i<0||j<0)){
           return;
       }
       if(visited[i][j]==true||matrix[i][j]==1){
           return ;
       }
       visited[i][j]=true;
       dfs(visited,i+1,j,N,M,matrix);
       dfs(visited,i-1,j,N,M,matrix);
       dfs(visited,i,j+1,N,M,matrix);
       dfs(visited,i,j-1,N,M,matrix);
    }
        
    int closedIsland(vector<vector<int>>& matrix) {
        int N=matrix.size();
        int M=matrix[0].size();
       vector<vector<bool>> visited(N,vector<bool> (M,false));
        for(int i=0;i<M;i++){
            if(matrix[0][i]==0&&visited[0][i]==false){
                 dfs(visited,0,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][0]==0&&visited[i][0]==false){
                 dfs(visited,i,0,N,M,matrix);
            }
        }
        for(int i=0;i<M;i++){
            if(matrix[N-1][i]==0&&visited[N-1][i]==false){
              dfs(visited,N-1,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][M-1]==0&&visited[i][M-1]==false){
                 dfs(visited,i,M-1,N,M,matrix);
            }
        }
        int count=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j]==0&&visited[i][j]==false){
                   dfs(visited,i,j,N,M,matrix);
                   count++;
                }
            }
        }
        return count;
    }
};