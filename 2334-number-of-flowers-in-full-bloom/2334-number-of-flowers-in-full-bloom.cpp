#define  flower flowers
class Solution {
    int M=1e5;
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        //Current Flower= Number of flowers bloom - Number of flowers died 
        vector<int> bloom(flowers.size()),endedbloom(flowers.size());
        for(int i=0;i<flowers.size();i++){
            bloom[i]=flowers[i][0];
            endedbloom[i]=flowers[i][1];
        }
        sort(bloom.begin(),bloom.end());
        vector<int> ans(people.size(),0);
        sort(endedbloom.begin(),endedbloom.end());
        for(int i=0;i<people.size();i++){
            ans[i]=upper_bound(bloom.begin(),bloom.end(),people[i])-bloom.begin();
            ans[i]=ans[i]-(lower_bound(endedbloom.begin(),endedbloom.end(),people[i])-endedbloom.begin());
        }
        return ans;
    }
};