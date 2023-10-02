class Solution {
public:
    bool winnerOfGame(string colors) {
        int i=1,j=1;
        int cA=0;
        int cB=0;
        int n=colors.size();
        if(n<=2) return false;
        for(int i=1;i<n-1;i++){
            if(colors[i-1]=='A'&&colors[i]=='A'&&colors[i+1]=='A'){
                cA++;
            }
            else if(colors[i-1]=='B'&&colors[i]=='B'&&colors[i+1]=='B'){
                cB++;
            }
        }
        return cA>cB;
    }
};