class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int level=0;level<n/2;level++){
            for(int i=level;i<n-1-level;i++){
                int j=n-1-level;
                swap(matrix[level][i],matrix[i][j]);
                swap(matrix[level][i],matrix[n-1-level][n-1-i]);
                swap(matrix[level][i],matrix[n-1-i][level]);
            }
        }
    }
};