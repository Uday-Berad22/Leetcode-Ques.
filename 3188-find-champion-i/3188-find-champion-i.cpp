class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        int mm=grid[0].size();
        int maxi=INT_MIN;
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<mm;j++){
                if(i!=j&&grid[i][j]==1){
                    m[i]++;
                }
                else{
                    m[j]++;
                }
            }
        }
        for(auto a: m){
            if(a.second>maxi){
                maxi=a.second;
                ans=a.first;
            }
        }
        return ans;
    }
};