class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;      
        int n=mat.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(auto &j: mat[i]){
                if(j==1)cnt++;
            }
            pq.push({cnt,i});
        }
         while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};