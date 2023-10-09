class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
        if(!binary_search(v.begin(),v.end(),x))
        {
            return {-1,-1};
        }
        int a=lower_bound(v.begin(),v.end(),x)-v.begin();
        int b=(upper_bound(v.begin(),v.end(),x)-v.begin()-1);
        return {a,b};
    }
};