class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        int j=0;
        int k=0;
       vector<int> ans(n);
       for(int i=0;i<n;i++){
           if(i%2==0){
               while(nums[j]<0){
                   j++;
               }
               ans[i]=nums[j];
               j++;
           }
           else{
               
               while(nums[k]>0){
                   k++;
               }
               ans[i]=nums[k];
               k++;
           
           }
           
       }
       return ans;
    }
};