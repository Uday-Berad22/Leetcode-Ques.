class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int> ans(n,0);
        vector<bool> visited(n,false);
        unordered_map<int,int> m;
        vector<int> Stack;
        for(int i=0;i<n;i++){
            int j=i;
            while(visited[j]==false&&ans[j]==0){
                visited[j]=true;
                m[j]=Stack.size();
                Stack.push_back(j);
                j=edges[j];
            }
            if(visited[j]==true){
                if(m.find(j)!=m.end()){
                    int k=Stack.size()-m[j];
                    for(int cnt=0;cnt<k;cnt++){
                        ans[Stack.back()]=k;
                        m.erase(Stack.back());
                        Stack.pop_back();
                    }
                }
            }
            while(Stack.size()>0){
                ans[Stack.back()]=ans[edges[Stack.back()]]+1;
                m.erase(Stack.back());
                Stack.pop_back();
            }
        }
        return ans;
    }
};