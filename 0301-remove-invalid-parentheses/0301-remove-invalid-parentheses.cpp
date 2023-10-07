class Solution {
public:
        void recurssion(set<string> &ans,string &s,int i,int cO,int cC,string &temp,int &maxi){
        if(i==s.size()){
            if(cO==cC&&temp.size()==maxi){
                ans.insert(temp);
            }
            return;
        }
        recurssion(ans,s,i+1,cO,cC,temp,maxi);
        if(s[i]!=')'){
            temp.push_back(s[i]);
            if(s[i]=='(')
            recurssion(ans,s,i+1,cO+1,cC,temp,maxi);
            else
            recurssion(ans,s,i+1,cO,cC,temp,maxi);
            temp.pop_back();
        }
        if(s[i]==')'&&cC<cO){
            temp.push_back(s[i]);
            recurssion(ans,s,i+1,cO,cC+1,temp,maxi);
            temp.pop_back();
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string temp="";
        int maxi=0;
        int siz;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'&&cnt2<cnt1){
                cnt2++;
            }
            else if(s[i]=='(')
            cnt1++;
            else if(s[i]!=')')
            cnt3++;
        }
        siz=min(cnt1,cnt2)*2+cnt3;
        vector<string> f_ans;
        recurssion(ans,s,0,0,0,temp,siz);
        for(auto &a: ans) {
            f_ans.push_back(a);
        }
        return f_ans;
    }
    
};