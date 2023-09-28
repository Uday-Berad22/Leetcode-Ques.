class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int j=0;
        for(int i=0;j<n&&i<n;i++){
            if(nums[i]%2==0) {
                continue;
            }
            if(j<i){
                j=i+1;
            }
            while(j<n&&nums[j]%2!=0){
                j++;
            }
            if(j>i&&j<n)
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};