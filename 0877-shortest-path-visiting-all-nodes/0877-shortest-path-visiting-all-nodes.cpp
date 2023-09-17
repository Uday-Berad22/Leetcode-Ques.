class mypair{
    public: 
    int a,b,c;
};
class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int size=(1<<n)-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            vector<vector<bool>> visited(n+1,vector<bool> (size+1,false));
            queue<mypair> q;
                   mypair obj1;
                    obj1.a=i;
                    obj1.b=1<<i;
                    obj1.c=0;
            q.push(obj1);
            while(!q.empty()){
                int x=q.front().a;
                int y=q.front().b;
                int z=q.front().c;
                q.pop();
                if(y==size){
                    cout<<i<<endl;
                    ans=min(ans,z);
                    break;
                }
                for(auto nbr: graph[x]){
                int y1=y|(1<<nbr);
                if(visited[nbr][y1]==false){
                    mypair obj;
                    obj.a=nbr;
                    obj.b=y1;
                    obj.c=1+z;
                    q.push(obj);
                    visited[nbr][y1]=true;
                }
             }
            }
        }
        return ans;
    }
};