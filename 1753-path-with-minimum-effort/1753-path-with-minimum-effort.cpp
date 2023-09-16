class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool check_DFS(vector<vector<int>> &heights,int &threeShold,int i,int j,vector<vector<bool>> &visited){
         int n=heights.size();int m=heights[0].size();
         if(i==n-1&&j==m-1) return true;
         visited[i][j]=true;
         for(auto &dir: directions){
             if((i+dir[0]>=0&&j+dir[1]>=0)&&(i+dir[0]<n&&j+dir[1]<m)&&(visited[i+dir[0]][j+dir[1]]==false&&abs(heights[i][j]-heights[i+dir[0]][j+dir[1]])<=threeShold)){
                    if(check_DFS(heights,threeShold,i+dir[0],j+dir[1],visited)==true){
                        return true;
                    }
                }
         }
         return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=-1;
        int high=1e6;
        while(high-low>1){
            int mid=(high+low)/2;
            vector<vector<bool>> visited(heights.size(),vector<bool> (heights[0].size(),false));
            if(check_DFS(heights,mid,0,0,visited)==true){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return high;
    }
};