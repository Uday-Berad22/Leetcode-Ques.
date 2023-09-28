class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        int i=0;
        while(j>i){
            if(nums[i]%2!=0&&nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]%2==0){
                i++;
            }
            if(nums[j]%2!=0){
                j--;
            }
        }
        return nums;
    }
};