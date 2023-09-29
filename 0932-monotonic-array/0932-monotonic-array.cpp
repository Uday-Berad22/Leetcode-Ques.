class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int  flag=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]&&flag==1){
                return false;
            }   
            if(nums[i]<nums[i+1]&&flag==-1){
                return false;
            } 
           if(nums[i]>nums[i+1]){
                flag=-1;
                continue;
            }
            if(nums[i]<nums[i+1]){
                flag=1;
                continue;
            }
        }
        return true;
    }
};