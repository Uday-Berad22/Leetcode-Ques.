class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        vector<int> nums1(n);
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            nums1[i]=((i+1)-m.size());
        }
        int ans=nums.size();
        for(int i=0;i<n;i++){
            int j=upper_bound(nums.begin(),nums.end(),nums[i]+(n-1))-nums.begin();
            int m=nums1[j-1]-nums1[i];
            ans=min(ans,(i+n-j+m));
        }
        return ans;
    }
};