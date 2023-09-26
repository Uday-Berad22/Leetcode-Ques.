class Solution {
public:
    string smallestSubsequence(string s) {
           string ans;
           int freq[26]={0};
           int freq_ans[26]={0};
           for(int i=0;i<s.size();i++){
               freq[s[i]-'a']++;
           }
           for(int i=0;i<s.size();i++){
               freq[s[i]-'a']--;
               if(freq_ans[s[i]-'a']>0) continue;
               while(ans.size()>0&&ans.back()>s[i]&&freq[ans.back()-'a']>0){
                   freq_ans[ans.back()-'a']--;
                   ans.pop_back();
               }
               ans.push_back(s[i]);
               freq_ans[s[i]-'a']++;
           }
           return ans;
    }
};