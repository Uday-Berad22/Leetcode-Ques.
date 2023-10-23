class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0||__builtin_popcount(n)>1) return false;
        if(((int)log2(n))%2==0) return true;
        return false;
    }
};