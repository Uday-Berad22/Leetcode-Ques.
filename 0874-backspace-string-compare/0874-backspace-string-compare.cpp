class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'&&st.size()>0){
                st.pop();
            }
            else if(s[i]!='#'){
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'&&st.size()>0){
                st.pop();
            }
            else if(t[i]!='#'){
                st.push(t[i]);
            }
        }
        t="";
        while(!st.empty()){
            t.push_back(st.top());
            st.pop();
        }
        return t==s;
    }
};