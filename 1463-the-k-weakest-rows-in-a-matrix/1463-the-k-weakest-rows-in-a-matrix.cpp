class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;      
        priority_queue<pair<int,int>> pq;
        int n=mat.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            int high=mat[i].size();
            int low=-1;
            while(high-low>1){
                int mid=(high+low)/2;
                if(mat[i][mid]==1){
                    low=mid;
                }
                else{
                    high=mid;
                }
            }
            if(high==mat[i].size()) cnt=mat[i].size();
            else cnt=low+1;
            pq.push({cnt,i});
            if(pq.size()>k) pq.pop();
        }
         while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};