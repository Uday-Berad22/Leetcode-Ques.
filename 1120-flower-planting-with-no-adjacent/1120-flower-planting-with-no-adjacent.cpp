class Solution {
public:
bool dfs(int i,vector<vector<int>> &graph,int m,int n,vector<int> &colors){
        if(colors[i]!=0) return true;
        for(int k=1;k<=m;k++){
            int flag=0;
            for(auto &j: graph[i]){
                    if(colors[j]==k){
                        flag=1;
                        break;
                    }
            }
            if(flag==0){
                int flag1=0;
                colors[i]=k;
                for(auto &j: graph[i]){
                    if(colors[j]==0){
                        if(dfs(j,graph,m,n,colors)==false){
                            flag1=1;
                            break;
                        }
                    }
                }
               if(flag1==0){
                   return true;
               }
            }
        }
        colors[i]=0;
        return false;
    }
   
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for(auto &a: paths){
            graph[a[0]-1].push_back(a[1]-1);
            graph[a[1]-1].push_back(a[0]-1);
        }
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            dfs(i,graph,4,n,colors);
        }
        return colors;
    }
};