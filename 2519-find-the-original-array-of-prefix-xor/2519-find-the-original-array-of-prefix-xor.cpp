class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int prev=pref[0];
        for(int i=1;i<n;i++){
            int prev1=pref[i];
            pref[i]=prev^pref[i];
            prev=prev1;
        }
        return pref;
    }
};