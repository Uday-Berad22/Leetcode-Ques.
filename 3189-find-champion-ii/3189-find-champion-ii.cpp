class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
                unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[i]=0;   
        }

        for(auto ed: edges){
            m[ed[1]]++;
            m[ed[0]]=m[ed[0]];
        }
        int ans=0;
        int count=0;
        for(auto a: m){
            if(a.second==0){
                ans=a.first;
                count++;
            }
        }
        return (count>1||(count==0&&n>1))?-1:ans;
    }
};