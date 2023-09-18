class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(auto &a : nums){
            s.insert(a);
        }
        int ans=0;
        while(s.size()>0){
            auto a=*(s.begin());
            m[a]=1;
            int i=1;
            s.erase(a);
            while(s.find(a+i)!=s.end()){
                m[a]++;
                s.erase(a+i);
                i++;
            }
            m[a]+=m[a+i];
             ans=max(ans,m[a]);
        }
        return ans;
    }
};