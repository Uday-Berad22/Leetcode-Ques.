class Solution {
public:
    bool detect_cycle(int n, vector<int>& leftChild, vector<int>& rightChild,vector<bool> &visited,int i,int &cnt){
        if(i==-1) return false;
        if(visited[i]==true) return true;
        visited[i]=true;
        cnt++;
        bool ans=(detect_cycle(n,leftChild,rightChild,visited,leftChild[i],cnt)||
        detect_cycle(n,leftChild,rightChild,visited,rightChild[i],cnt));
        visited[i]=false;
        return ans;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[i]=0;
        }
        for(auto a: leftChild){
            m[a]++;
        }
        for(auto a: rightChild){
            m[a]++;
        }
        vector<int> v;
        for(auto a: m){
            if(a.first!=-1&&a.second>1){
                return false;
            }
            if(a.second==0){
                v.push_back(a.first);
            }
        }
        vector<bool> visited(n,false);
        int count=0;
        for(auto &i: v){
            int cnt=0;
            if(detect_cycle(n,leftChild,rightChild,visited,i,cnt)==true)      {
                return false;
            }
            count=max(count,cnt);
        }
        return count<n?false:true;
    }
};