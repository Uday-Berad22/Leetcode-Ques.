class Myclass{  
    public:
    int x,y,val;
    Myclass(int x,int y,int val){
        this->x=x;
        this->y=y;
        this->val=val;
    }
};
class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<Myclass> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {  
                    Myclass obj(i,j,0);
                    q.push(obj);
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            Myclass obj=q.front();
            q.pop();
            for(auto &dir: directions){
                int i=obj.x+dir[0];
                int j=obj.y+dir[1];
                if(i<n&&j<n&&i>=0&&j>=0&&grid[i][j]==0){
                    Myclass object(i,j,obj.val+abs(i-obj.x)+abs(j-obj.y));
                    grid[i][j]=1;
                    q.push(object);
                    ans=max(ans,obj.val+abs(i-obj.x)+abs(j-obj.y));
                }
            }
        }
        return ans;
    }
};