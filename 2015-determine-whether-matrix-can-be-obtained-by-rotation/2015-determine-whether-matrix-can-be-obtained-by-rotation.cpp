class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n=matrix.size();
        for(int level=0;level<n/2;level++){
            for(int i=level;i<n-1-level;i++){
                swap(matrix[level][i],matrix[i][n-1-level]);
                swap(matrix[level][i],matrix[n-1-level][n-1-i]);
                swap(matrix[level][i],matrix[n-1-i][level]);
            }
        }
       int  count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target[i][j]) count++;
            }
        }
        if(count==n*n) return true;
         for(int level=0;level<n/2;level++){
            for(int i=level;i<n-1-level;i++){
                swap(matrix[level][i],matrix[i][n-1-level]);
                swap(matrix[level][i],matrix[n-1-level][n-1-i]);
                swap(matrix[level][i],matrix[n-1-i][level]);
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target[i][j]) count++;
            }
        }
        if(count==n*n) return true;
         for(int level=0;level<n/2;level++){
            for(int i=level;i<n-1-level;i++){
                swap(matrix[level][i],matrix[i][n-1-level]);
                swap(matrix[level][i],matrix[n-1-level][n-1-i]);
                swap(matrix[level][i],matrix[n-1-i][level]);
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target[i][j]) count++;
            }
        }
        if(count==n*n) return true;
        for(int level=0;level<n/2;level++){
            for(int i=level;i<n-1-level;i++){
                swap(matrix[level][i],matrix[i][n-1-level]);
                swap(matrix[level][i],matrix[n-1-level][n-1-i]);
                swap(matrix[level][i],matrix[n-1-i][level]);
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target[i][j]) count++;
            }
        }
        if(count==n*n) return true;
        return false;
    }
};