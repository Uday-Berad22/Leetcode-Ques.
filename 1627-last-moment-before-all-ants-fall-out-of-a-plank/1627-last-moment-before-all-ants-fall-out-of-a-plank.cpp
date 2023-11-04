class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int a=INT_MIN;
        for(auto &x: left){
            a=max(a,abs(0-x));
        }
        int b=INT_MIN;
        for(auto &x: right){
            b=max(b,abs(n-x));
        }
        return max(a,b);
    }
};