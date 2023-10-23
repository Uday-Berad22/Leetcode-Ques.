class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int x=__builtin_popcount(n);
        if(x>1) return false;
        int c=(int)log2(n) ;
        if(c%2==0) return true;
        return false;
    }
};