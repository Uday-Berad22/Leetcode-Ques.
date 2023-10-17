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
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
          
            if(leftChild[i]!=-1)
            {
                if(parent[i]==parent[leftChild[i]]){
                    return false;
                }
                m[leftChild[i]]++;
                parent[leftChild[i]]=parent[i];
            }
            if(rightChild[i]!=-1)
            {
                if(parent[i]==parent[rightChild[i]]){
                    return false;
                }
                m[rightChild[i]]++;
                parent[rightChild[i]]=parent[i];
            }
            m[i]+=0;
        }
        int cnt=0;
        for(auto a: m){
            if(a.second>1){
                return false;
            }
            if(a.second==0) cnt++;
        }
        return cnt==1?true:false;
    }
};