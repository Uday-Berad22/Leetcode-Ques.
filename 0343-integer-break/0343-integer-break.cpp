class Solution {
public:
    
    int fun(int j,int n,vector<int> &v){
        if(j>n) return 1;
        int maxi=1;
        int pro=1;
        if(v[j]!=-1) return v[j];
        for(int i=j;i<=n;i++){
            maxi=max(maxi,pro*fun(i+1,n,v));
            if(pro==n-1) break;
            pro++;
        }
        return v[j]=maxi;
    }
    int integerBreak(int n) {
        if(n<=2) return 1;
        vector<int> v(n+1,-1);
        return fun(1,n,v);
    }
};