class Solution {
public:
    int find_set(int i,vector<int> &parent){
        if(parent[i]==-1) return i;
        return parent[i]=find_set(parent[i],parent);
    }   
    void union_set(int i,int j,vector<int> &parent,vector<int> &rank){  
        int s1=find_set(i,parent);
        int s2=find_set(j,parent);
        if(s1!=s2){
            if(rank[s1]>rank[s2]){
                rank[s1]+=rank[s2];
                parent[s2]=s1;
            }
            else{
                rank[s2]+=rank[s1];
                parent[s1]=s2;
            }
        }
        return ; 
    }
    bool detect_cycle(int i,int j,vector<int> &parent,vector<int> &rank){
        int s1=find_set(i,parent);
        int s2=find_set(j,parent);
        if(s1!=s2){
            union_set(i,j,parent,rank);
            return false;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //By using Kruskal's Algorithm ,Here We are creating edge list between two points and the weight between them is manhattan distance. And we are finding the MST and returning the sum of edges of MST
        int n=points.size();
        int ans=0;
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        vector<int> parent(points.size(),-1);
        vector<int> rank(points.size(),0);
        for(auto edge: edges){
            if(!detect_cycle(edge[1],edge[2],parent,rank)){
                ans+=edge[0];//adding the weight
            }
        }
        
        return ans;
    }
};