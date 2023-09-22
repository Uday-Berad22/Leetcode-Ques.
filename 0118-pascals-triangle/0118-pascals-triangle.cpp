class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> cur,prev;
        vector<vector<int>> Pascals_Triangle;
        for(int i=0;i<numRows;i++){
            cur.resize(i+1,1);
            for(int j=1;j<i;j++){
                cur[j]=prev[j]+prev[j-1];
            }
            prev=cur;
            Pascals_Triangle.push_back(cur);
        }
        return Pascals_Triangle;
    }
};