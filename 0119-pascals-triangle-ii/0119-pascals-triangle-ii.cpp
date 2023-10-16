class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev(1,1),cur;
        for(int i=0;i<=n;i++){
            cur.resize(i+1,1);
            for(int j=1;j<i;j++){
                cur[j]=prev[j-1]+prev[j];
            }
            prev=cur;
        }
        return cur;
    }
};