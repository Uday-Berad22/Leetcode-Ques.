class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,a=-1,b=-1,n=nums.size();
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                c1++;
            }
            else if(nums[i]==b){
                c2++;
            }
            else if(c1==0){
                c1++;
                a=nums[i];
            }
            else if(c2==0){
                c2++;
                b=nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a) c1++;
            else if(nums[i]==b) c2++;
        }
        if(c1>(n/3)){
            v.push_back(a);
        }
        if(c2>(n/3)){
            v.push_back(b);
        }
        return v;
    }
};