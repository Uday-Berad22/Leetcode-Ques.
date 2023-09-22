class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int total=m*n;
        vector<int> spiralOrder_ans(total);
        int cnt=0;
        int srow=0;
        int erow=m-1;
        int scol=0;
        int ecol=n-1;
        while(cnt<total){
            for(int col=scol;col<=ecol&&cnt<total;col++){
                spiralOrder_ans[cnt]=matrix[srow][col];
                cnt++;
            }
            srow++;
            for(int row=srow;row<=erow&&cnt<total;row++){
               spiralOrder_ans[cnt]=matrix[row][ecol];
                cnt++;
            }
            ecol--;
            for(int col=ecol;col>=scol&&cnt<total;col--){
                spiralOrder_ans[cnt]=matrix[erow][col];
                cnt++;
            }
            erow--;
            for(int row=erow;row>=srow&&cnt<total;row--){
                spiralOrder_ans[cnt]=matrix[row][scol];
                cnt++;
            }
            scol++;
        }
        return spiralOrder_ans;
    }
};