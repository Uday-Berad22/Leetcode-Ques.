class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Pascals_Triangle(numRows);
        for(int i=0;i<numRows;i++){
            Pascals_Triangle[i].resize(i+1,1);
            for(int j=1;j<i;j++){
                Pascals_Triangle[i][j]=Pascals_Triangle[i-1][j]+Pascals_Triangle[i-1][j-1];
            }
        }
        return Pascals_Triangle;
    }
};