class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> v;
        vector<vector<int>> graph(n);
        unordered_map<int,int> m;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            m[edges[i][1]]++;
            m[edges[i][0]]++;
        }
        queue<int> q;
        for(auto &a:m){
            if(a.second==1){
                q.push(a.first);
            }
        }
        queue<int> q2;
        while(!q.empty()){
            q2=q;
            int qsiz=q.size();
            while(qsiz--){
                int node=q.front();
                q.pop();
                for(auto &nbr: graph[node]){
                    m[nbr]--;
                    if(m[nbr]==1){
                        q.push(nbr);
                        m[nbr]=INT_MAX;
                    }
                }
            }
            
        }
        while(!q2.empty()){
        v.push_back(q2.front());
        q2.pop();
        }
        if(v.size()==0) v.push_back(0);
        return v;
    }
};