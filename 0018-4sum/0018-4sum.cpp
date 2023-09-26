#define ll long long 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tt) {
        set<vector<int> > ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                long long  tempi=tt-(arr[i]);
                tempi-=arr[j];
                if(tempi<=INT_MIN||tempi>=INT_MAX) continue;
                int t=tt-(arr[i]+arr[j]);
                while(k<l){
                    if(arr[k]+arr[l]==t){
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        ans.insert(temp);
                        if(arr[k+1]+arr[l]<=t){
                            k++;
                        }
                        else{
                            l--;
                        }
                    }
                    else if(arr[k]+arr[l]<t){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        // cout<<"-------------------- "<<endl;
        vector<vector<int>> fans;
        for(auto a: ans){
            fans.push_back(a);
        }
        return fans;
    }
};