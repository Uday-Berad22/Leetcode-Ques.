class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<char> stk;
        long long  cnt=1;
        stk.push(s[0]);
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
            stk.push(s[i]);
        }
        if(cnt==k){
             while((stk.top()<='9'&&stk.top()>='1')){
                    stk.pop();
            
             } 
        }
        else
        {while(cnt>=k){
            // if(stk.size()==k) break;
            // if(k==cnt) break;
            if(stk.top()<='9'&&stk.top()>='1'){
                cnt=cnt/(stk.top()-'0');
            }
            else{
                cnt--;
            }
            if(cnt==0)break;
            if(cnt<=k){
                k=k%cnt;
            }
            stk.pop();
            if(k==0){
                while((stk.top()<='9'&&stk.top()>='1')){
                    stk.pop();
                }
                break;
            }
            // if(stk.size()==k) break;
        }}
        string ans;
        ans.push_back(stk.top());
        return ans;
    }
};