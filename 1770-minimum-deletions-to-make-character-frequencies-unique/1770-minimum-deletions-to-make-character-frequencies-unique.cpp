class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m,freq;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int count=0;
        for(auto a: m){
            if(freq[a.second]>0){
                int j=a.second;
                while(j>0){
                    if(freq[j]==0){
                        freq[j]++;
                        break;
                    }
                    count++;
                    j--;
                }
            }
            freq[a.second]++;
        }
        return count;
    }
};