class Myclass{
    public:
    int x;
    int y;
    int time;
    Myclass(int x,int y,int time){
        this->x=x;
        this->y=y;
        this->time=time;
    }
};
class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<Myclass> q;
        int freshcnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    Myclass obj(i,j,0);
                    q.push(obj);
                }
                if(grid[i][j]==1)freshcnt++;
            }
        }
        int ans=0;
        int count=0;
        int cnt=q.size();
        while(!q.empty()){
            Myclass obj=q.front();
            q.pop();
            if(grid[obj.x][obj.y]==-1) continue;
            grid[obj.x][obj.y]=-1;
            count++;
            ans=max(ans,obj.time);
            for(auto &dir: directions){
                int i=obj.x+dir[0];
                int j=obj.y+dir[1];
                if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]==1&&grid[i][j]!=-1){
                    Myclass object(i,j,obj.time+1);
                    q.push(object);
                }
            }
        }
        if(count-cnt<freshcnt) return -1;
        return ans;
    }
};