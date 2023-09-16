class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool check(vector<vector<int>> &heights,int &threeShold){
        priority_queue<pair<int,int>> q;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        q.push({0,0});
        visited[0][0]=true;
        int count=0;
        while(!q.empty()){
            int i=q.top().first;
            int j=q.top().second;
            q.pop();

            count++;
            // if(count>100) return false;
            visited[i][j]=true;
            if(i==n-1&&j==m-1) return true;
            for(auto dir: directions){
                if((i+dir[0]>=0&&j+dir[1]>=0)&&(i+dir[0]<n&&j+dir[1]<m)&&(visited[i+dir[0]][j+dir[1]]==false&&abs(heights[i][j]-heights[i+dir[0]][j+dir[1]])<=threeShold)){
                    q.push({i+dir[0],j+dir[1]});
                    visited[i+dir[0]][j+dir[1]]=true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=-1;
        int high=1e7;
        int count=0;
        while(high-low>1){
            int mid=(high+low)/2;
            if(check(heights,mid)==true){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return high;
    }
};