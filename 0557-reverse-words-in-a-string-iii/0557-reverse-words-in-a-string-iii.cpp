class Solution {
public:
    string reverseWords(string s) {
        int j=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(s.begin()+j,s.begin()+i);
                j=i+1;
            }
        }
        reverse(s.begin()+j,s.begin()+n);
        return s;
    }
};