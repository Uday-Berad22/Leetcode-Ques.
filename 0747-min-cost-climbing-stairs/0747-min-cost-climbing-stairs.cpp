class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int next=0,next_to_next=0;
        for(int i=n-1;i>=0;i--){
            int current;
            current=min(next,next_to_next)+cost[i];
            next_to_next=next;
            next=current;
        }
        return min(next,next_to_next);
    }
};