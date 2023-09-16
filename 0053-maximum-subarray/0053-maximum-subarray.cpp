class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
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