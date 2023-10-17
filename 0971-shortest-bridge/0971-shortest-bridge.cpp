class MyClass{
    public:
    int x;
    int y;
    int val;
    MyClass(int i,int j,int val){
        x=i;
        y=j;
        this->val=val;
    }
};
class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    void DFS(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid,queue<MyClass> &q){
        int n=visited.size();
        if(i>=n||j>=n||i<0||j<0||grid[i][j]==0||visited[i][j]==true) return;
        cout<<i<<" "<<j<<endl;
        visited[i][j]=true;
        MyClass Obj(i,j,0);
        q.push(Obj);
        for(auto &dir: directions)
        DFS(i+dir[0],j+dir[1],visited,grid,q);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        queue<MyClass> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==false)
                { 
                   DFS(i,j,visited,grid,q);
                   goto lable;
                }
            }
        }

        lable:
        while(!q.empty()){
            MyClass obj=q.front();
            q.pop();
            // cout<<obj.x<<" "<<obj.y<<" "<<obj.val<<endl;
            for(auto &dir: directions){
                int i=obj.x+dir[0];
                int j=obj.y+dir[1];
                if(i>=0&&j>=0&&i<n&&j<n&&visited[i][j]==false){
                   visited[i][j]=true;
                   if(grid[i][j]==1) return obj.val;
                   MyClass object(i,j,obj.val+1);
                   q.push(object);
                }
            }
        }
        return -1;
    }
};