class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> front(n);
        front[0]=nums[0];
        for(int i=1;i<n;i++){
            front[i]=min(nums[i-1],front[i-1]);
        }
        priority_queue <int, vector<int>, greater<int> > pq;
        pq.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>front[i]){
                while(!pq.empty()&&pq.top()<=front[i]){
                    pq.pop();
                }
                if(!pq.empty()&&pq.top()<nums[i]&&pq.top()>front[i]){
                    return true;
                }
                pq.push(nums[i]);
            }
        }
        return false;
        
    }
};