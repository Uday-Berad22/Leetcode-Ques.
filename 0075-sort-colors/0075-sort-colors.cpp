class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cn1=0,cn2=0,cn0=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cn1++;
            }
            else if(nums[i]==2){
                cn2++;
            }
            else if(nums[i]==0){
                cn0++;
            }
        }
        for(int i=0;i<cn0;i++){
            nums[i]=0;
        }
        for(int i=0;i<cn1;i++){
            nums[i+cn0]=1;
        }
         for(int i=0;i<cn2;i++){
            nums[i+cn0+cn1]=2;
        }
    }
};