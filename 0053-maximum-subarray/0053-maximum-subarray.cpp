class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           ans=max(nums[i],ans);
           if(nums[i]+sum<0){
                sum=0;
            }
            else{
                sum=sum+nums[i];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};