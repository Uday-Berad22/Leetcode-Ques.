class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag=0;
        for(int col=0;col<matrix[0].size();col++){
            if(matrix[0][col]==0){ flag=1;break;}
        }
        for(int row=1;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                if(matrix[row][col]==0){
                    matrix[0][col]=0;
                    matrix[row][0]=0;
                }
            }
        }
        for(int row=1;row<matrix.size();row++){
            if(matrix[row][0]==0){
                for(int col=0;col<matrix[0].size();col++){
                    matrix[row][col]=0;
                }
            }
        }
        for(int col=0;col<matrix[0].size();col++){
            if(matrix[0][col]==0){
                for(int row=1;row<matrix.size();row++){
                    matrix[row][col]=0;
                }
            }
        }
        if(flag==1){
            for(int col=0;col<matrix[0].size();col++){
                 matrix[0][col]=0;
            }
        }
    }
};