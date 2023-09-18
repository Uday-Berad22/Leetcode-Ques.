class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        int ans=0;
        nums.push_back(INT_MAX);
         int n=nums.size();
        for(int i=0;i<n-1;i++){
            long long num=nums[i];
            if(abs(num-nums[i+1])==1){
                count++;
            }
            else if(abs(num-nums[i+1])>1){
                count++;
                ans=max(count,ans);
                count=0;
            }
        }
        ans=max(count,ans);
        return ans;
    }
};