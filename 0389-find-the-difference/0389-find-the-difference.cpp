class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            m[t[i]]--;
            if(m[t[i]]<0) return t[i];
        }
        return 'a';
    }
};