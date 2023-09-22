class Solution {
    vector<vector<int>> Pascals_Triangle;
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> cur_row;
        if(numRows==1){
            cur_row.push_back(1);
            Pascals_Triangle.push_back(cur_row);
            return Pascals_Triangle;
        }
        cur_row.push_back(1);
        vector<int> prev=generate(numRows-1).back();
        for(int i=1;i<numRows-1;i++){
            cur_row.push_back(prev[i]+prev[i-1]);
        }
        cur_row.push_back(1);
        Pascals_Triangle.push_back(cur_row);
        return Pascals_Triangle;
    }
};