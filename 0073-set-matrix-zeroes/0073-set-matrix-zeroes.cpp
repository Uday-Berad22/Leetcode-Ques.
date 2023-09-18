class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag=0;

        //Checking if any zero is present in first row if present then flag=1;
        for(int col=0;col<matrix[0].size();col++){
            if(matrix[0][col]==0){ flag=1;break;}
        }

        // if Zero is present in a row then make row's first element as zero and
        // make first row having that column  element as zero
        // e.g if a[1][2]==0 then make a[1][0]=0 and a[0][2]=0
        for(int row=1;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                if(matrix[row][col]==0){
                    matrix[0][col]=0;
                    matrix[row][0]=0;
                }
            }
        }


         //Making rows as zeroes if zero is present in it
        for(int row=1;row<matrix.size();row++){
            if(matrix[row][0]==0){
                for(int col=0;col<matrix[0].size();col++){
                    matrix[row][col]=0;
                }
            }
        }

       //Making coloumn as zeroes if zero is present in it
        for(int col=0;col<matrix[0].size();col++){
            if(matrix[0][col]==0){
                for(int row=1;row<matrix.size();row++){
                    matrix[row][col]=0;
                }
            }
        }

        // Checking if any zeroes is present in first row then make first row elements as zeroes
        if(flag==1){ 
            for(int col=0;col<matrix[0].size();col++){
                 matrix[0][col]=0;
            }
        }
    }
};