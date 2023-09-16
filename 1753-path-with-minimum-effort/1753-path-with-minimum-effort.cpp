class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size(); 
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> val(n,vector<int> (m,INT_MAX));
        val[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int value=pq.top().first;
            pq.pop();
            if(i==n-1&&j==m-1) {return value;}
            for(auto dir: directions){
                if(i+dir[0]>=0&&j+dir[1]>=0&&i+dir[0]<n&&j+dir[1]<m){
                    if(val[i+dir[0]][j+dir[1]]>(abs(heights[i][j]-heights[i+dir[0]][j+dir[1]]),value)){
                        val[i+dir[0]][j+dir[1]]=max(abs(heights[i][j]-heights[i+dir[0]][j+dir[1]]),value);
                        pq.push({val[i+dir[0]][j+dir[1]],{i+dir[0],j+dir[1]}});
                    }
                }
            }
        } 
        return INT_MAX;
    }
};