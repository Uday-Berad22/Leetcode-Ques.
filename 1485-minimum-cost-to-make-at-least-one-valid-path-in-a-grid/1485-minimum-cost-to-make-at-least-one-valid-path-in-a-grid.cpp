class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
         priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq; 
         pq.push({0,{0,0}});
         vector<vector<bool>> visited(m,vector<bool>(n,false));
         while(!pq.empty()){
             int x=pq.top().second.first;
             int y=pq.top().second.second;
             int val=pq.top().first;
             pq.pop();
             if(visited[x][y]==true) continue;
             if(x==m-1&&y==n-1){
                 return val;
             }
             visited[x][y]=true;
             for(auto &dir: directions){
                 int xx=x+dir[0];
                 int yy=y+dir[1];
                 int value=1;
                 if(xx<m&&yy<n&&xx>=0&&yy>=0&&visited[xx][yy]==false){
                     if(grid[x][y]==1&dir[1]==1){
                         value=0;
                     }
                     if(grid[x][y]==2&dir[1]==-1){
                         value=0;
                     }
                     if(grid[x][y]==3&dir[0]==1){
                         value=0;
                     }
                     if(grid[x][y]==4&dir[0]==-1){
                         value=0;
                     }
                     value=value+val;
                     pq.push({value,{xx,yy}});
                 }
             }
         }
         return 0;
    }
};