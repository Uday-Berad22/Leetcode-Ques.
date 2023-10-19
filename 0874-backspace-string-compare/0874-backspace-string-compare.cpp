class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        int j=s.size()-1;
        int count=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                count++;
                continue;
            }
            while(count>0&&i>=0){
                if(s[i]=='#')
                count++;
                else
                count--;
                i--;
            
            }
              if(i<0) break;
             if(s[i]=='#'){
                count++;
                continue;
            }
              
                count=0;
                s[j]=s[i];
                j--;
        }
        s=s.substr(j+1);
        j=t.size()-1;
        count=0;
         for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                count++;
                continue;
            }
            while(count>0&&i>=0){
                if(t[i]=='#')
                count++;
                else
                count--;
                i--;
            
            }
              if(i<0) break;
             if(t[i]=='#'){
                count++;
                continue;
            }
               
                count=0;
                t[j]=t[i];
                j--;
        }
        t=t.substr(j+1,t.size()-(j+1));
        return t==s;
    }
};