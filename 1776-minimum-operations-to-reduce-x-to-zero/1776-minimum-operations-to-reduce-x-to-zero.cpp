class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=accumulate(nums.begin(),nums.end(),0);
        long long target=sum-x;
        if(sum<x) return -1;
        long long prefix=0;
        int j=0;
        int msize=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            while(prefix>target){
                prefix-=nums[j++];
            }
            if(prefix==target) msize=max(msize,i-j+1);
        }
        if(msize==INT_MIN) return -1;
        return nums.size()-msize;
    }
};