class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long  cnt=1;
        int j=0;
        for(int i=1;i<s.size();i++){
            if(cnt>=k){
                break;
            }
            if(s[i]<='9'&&s[i]>='1'){
                cnt=cnt*(s[i]-'0');
            }
            else{
                cnt++;
            }
            j++;
        }
        int i=j;
        if(cnt==k){
             while((s[i]<='9'&&s[i]>='1')){
                    i--;
            
             } 
        }
        else
        {while(cnt>=k){
            if(s[i]<='9'&&s[i]>='1'){
                cnt=cnt/(s[i]-'0');
            }
            else{
                cnt--;
            }
            if(cnt==0)break;
            if(cnt<=k){
                k=k%cnt;
            }
            i--;
            if(k==0){
                while((s[i]<='9'&&s[i]>='1')){
                    i--;
                }
                break;
            }
        }}
        string ans;
        ans.push_back(s[i]);
        return ans;
    }
};