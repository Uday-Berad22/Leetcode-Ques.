class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int total_and=nums[0];
        for(auto &num: nums) total_and= total_and&num;
        if(total_and!=0) return  1;
        int count=0;
        int last=nums[0];
        for(int i=0;i<nums.size();i++){
            last=nums[i]&last;
            if((last&nums[i])==0){
                count++;
                if(i<nums.size()-1)
                last=nums[i+1];
            }
        }
        return count;
    }
};