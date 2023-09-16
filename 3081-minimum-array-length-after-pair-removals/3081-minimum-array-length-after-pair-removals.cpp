#define nums v
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& v) {
        int n=v.size();
        int j=(n+1)/2;
        int i=0;
        int ans=n;
        while(i<(n+1)/2&&j<n){
            if(v[i]!=v[j]){
                i++;
                j++;
                ans-=2;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};