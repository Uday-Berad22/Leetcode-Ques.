class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n,vector<int> (n,0));
        for(int i=0;i<n;i++){   
            graph[i][i]=1;
        }
        for(auto &a: prerequisites){
            graph[a[0]][a[1]]=1;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][via]==1&&graph[via][j]==1){
                        graph[i][j]=1;
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto &query: queries){
            if(graph[query[0]][query[1]]==1){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};