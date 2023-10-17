class Solution {
public:
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(auto &dir: directions){
                    int x=i+dir[0];
                    int y=j+dir[1];
                    if(x>=0&&y>=0&&x<m&&y<n&&visited[x][y]==false){
                        isWater[x][y]=isWater[i][j]+1;
                    //      for(auto &dir: directions){
                    //         int xx=x+dir[0];
                    //         int yy=y+dir[1];
                    //         if(xx>=0&&yy>=0&&xx<m&&yy<n&&visited[xx][yy]==true){
                    //             if(abs(isWater[x][y]-isWater[xx][yy])>1){
                    //                 isWater[x][y]=isWater[i][j];
                    //             }
                    //         }
                    //    }
                        visited[x][y]=true;
                        q.push({x,y});
               }
            }
        }
        return isWater;
    }
};