class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                flag=true;
                break;
            }
        }
        if(flag==false) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                return false;
            }
        }
        return true;
    }
};