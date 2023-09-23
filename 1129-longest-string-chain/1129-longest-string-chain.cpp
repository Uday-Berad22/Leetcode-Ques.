class Solution {
public:
    static bool cmp(string &a,string &b) {return a.size()>b.size();}

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> m,length;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
            length[words[i]]=1;
        }
        int ans=1;
        for(auto &word : words){
            ans=max(ans,length[word]);
            for(int j=0;j<word.size();j++){
                string temp=word.substr(0,j)+word.substr(j+1,word.size()-(j+1));
                if(m[temp]>0){
                    length[temp]=max(length[temp],length[word]+1);
                }
            }
        }
        return ans;
    }
};