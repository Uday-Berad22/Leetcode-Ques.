class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(auto &a : nums){
            s.insert(a);
        }
        int ans=0;
        auto a=s.begin();
        int cnt=0;
        while(s.size()>0){
            int x=(*(a))-1;
            // cout<<x+1<<" "<<cnt<<" "<<ans<<endl;
            if(s.find(x)!=s.end()){
                a++;
                cnt=0;
            }
            else{
                s.erase(x+1);
                cnt++;
                ans=max(cnt,ans);
                if(s.find((x)+2)!=s.end()){
                    a=s.find((x)+2);
                }
                else{
                     a=s.begin();
                     cnt=0;
                }
            }
            
        }
        return ans;
    }
};