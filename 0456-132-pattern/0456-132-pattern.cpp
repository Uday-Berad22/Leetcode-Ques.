class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> front(n);
        front[0]=nums[0];
        for(int i=1;i<n;i++){
            front[i]=min(nums[i-1],front[i-1]);
        }
        set<int> st;
        st.insert(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>front[i]){
                auto it=st.upper_bound(front[i]);
                if(it!=st.end()){
                    if((*it)>front[i]&&(*it)<nums[i]){
                        return true;
                    }
                }
                st.insert(nums[i]);
            }
        }
        return false;
        
    }
};