class Solution {
    int M=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int> s(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<long long> v(n,1);
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0&&s.find(arr[i]/arr[j])!=s.end()){
                    int nn=arr[i]/arr[j];
                    v[i]=(v[i]+(v[m[nn]]*1LL*v[j])%M)%M;
                }
            }
        }
        for(int i=1;i<n;i++){
            v[i]=(v[i]+v[i-1])%M;
        }
        return v[n-1];
    }
};