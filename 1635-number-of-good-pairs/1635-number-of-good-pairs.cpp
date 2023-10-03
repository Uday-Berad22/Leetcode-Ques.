class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=m[nums[i]];
            m[nums[i]]++;
        }
        return ans;
    }
};