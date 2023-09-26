class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m,mp;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            m[s[i]]--;
             if(mp[s[i]]>=1){
                 continue;
             }
            while(!stk.empty()&&stk.top()>s[i]&&m[stk.top()]>0){
                mp[stk.top()]--;
                stk.pop();
            }
            if(mp[s[i]]<1)
           { stk.push(s[i]);
            mp[s[i]]++;}
        }
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};