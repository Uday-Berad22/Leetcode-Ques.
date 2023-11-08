class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy) return t!=1;
        int a=abs(sx-fx)+abs(sy-fy);
        int b=min(abs(sx-fx),abs(sy-fy));
        if(sx<fx)
        sx+=b;
        else
            sx-=b;
        if(sy<fy)
        sy+=b;
        else
            sy-=b;
        int c=abs(sx-fx)+abs(sy-fy)+b;
        if(c<=t) return true;
        return false;
    }
};