class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto a: nums) m[a]++;
        int mini=INT_MAX;
        for(auto a: m){
            mini=min(a.second,mini);
        }
        int ans=INT_MAX;
       
        for(int i=1;i<=mini;i++){
            int flag=0;
            int count=0;
            for(auto a: m)
            {
                int numgroups= a.second/(i+1);
                int remaining=a.second%(i+1);
                if(remaining==0){
                    count=count+numgroups;
                }
                else if(numgroups>=(i-remaining)){
                    count=count+numgroups+1;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<i<<" "<<count<<endl;
                ans=min(ans,count);
            }
        }
        return ans;
    }
};