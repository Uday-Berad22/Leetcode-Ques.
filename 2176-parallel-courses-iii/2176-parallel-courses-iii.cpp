class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n+1);
        unordered_map<int,int> m;
        for(int i=1;i<n+1;i++) m[i]+=0;
        for(int i=0;i<relations.size();i++){
            graph[relations[i][0]].push_back(relations[i][1]);
            m[relations[i][1]]++;
        }
        queue<pair<int,int>> q;
        vector<bool> visited(n+1,false);
        for(auto &a: m){
            if(a.second==0){
                visited[a.first]=true;
                q.push({a.first,time[a.first-1]});
            }
        }
        vector<int> ntime(n+1,0);
        int ans=0;
        while(!q.empty()){
            int x=0;
            int qsize=q.size();
            // queue<pair<int,int>> temp;
            for(int i=0;i<qsize;i++){
                pair<int,int> node=q.front();
                q.pop();
                ans=max(ans,node.second);
                for(auto &nbr:graph[node.first]){
                    if(visited[nbr]==false){
                        m[nbr]--;
                        ntime[nbr-1]=max(ntime[nbr-1],time[nbr-1]+node.second);
                        if(m[nbr]==0){
                            q.push({nbr,ntime[nbr-1]});
                            visited[nbr]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};