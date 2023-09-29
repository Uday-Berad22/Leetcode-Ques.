class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int  flag=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i==0&&nums[i]>nums[i+1]){
                flag=-1;
                continue;
            }
            if(i==0&&nums[i]<nums[i+1]){
                flag=1;
                continue;
            }
           
            if(nums[i]>nums[i+1]&&flag==1){
                return false;
            }   
            if(nums[i]<nums[i+1]&&flag==-1){
                return false;
            } 
             if(nums[i]<nums[i+1]){
                flag=1;
            }
             if(nums[i]>nums[i+1]){
                flag=-1;
            }  
        }
        return true;
    }
};