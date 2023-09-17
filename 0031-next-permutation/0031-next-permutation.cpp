class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0){
            int j=nums.size()-1;
            // if(nums[i]<nums[j]){
            //     swap(nums[i],nums[j]);
            //     sort(nums.begin()+i+1,nums.end());
            //     return;
            // }
            while(i<j&&nums[i]>=nums[j]){
                j--;
            }
            if(j-i>=1){
                swap(nums[i],nums[j]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
            i--;
        }
        sort(nums.begin(),nums.end());
    }
};