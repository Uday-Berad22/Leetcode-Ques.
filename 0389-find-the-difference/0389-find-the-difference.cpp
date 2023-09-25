class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0;
        for(int i=0;i<s.size();i++){
            int temp=s[i]-'a'+1;
            x=x^temp;
        }
        for(int i=0;i<t.size();i++){
           int temp=t[i]-'a'+1;
            x=x^temp;
        }
        return char('a'+x-1);
    }
};