class Solution {
    int M=1e9+7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> ans(k,0);
        vector<int> bits(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if((nums[i]>>j)&1){
                    bits[j]++;
                }
            }
        }
        for(int j=0;j<32;j++){
            for(int i=0;i<k&&bits[j]>0;i++){
                ans[i]=(ans[i]|(1<<j));
                bits[j]--;
            }
        }
        int fans=0;
        for(int i=0;i<k;i++){
            fans=(fans+(ans[i]*1LL*ans[i])%M)%M;
        }
        return fans;   
    }
};