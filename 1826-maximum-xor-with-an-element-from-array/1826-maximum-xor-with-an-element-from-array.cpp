class Node{
    public: 
    Node* link[2];
    Node(){
        link[0]=NULL;
        link[1]=NULL;
    }
};
class Trie{
    public: 
    Node *root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int x=((num>>i)&1);
            if(node->link[x]==NULL){
                node->link[x]=new Node();
            }
            node=node->link[x];
        }
    }
    int max_xor(int x){
        int ans=0;
        Node *node=root;
        for(int i=31;i>=0;i--){
               int bit=((x>>i)&1); 
               if(node->link[1-bit]!=NULL){
                ans=ans|(1<<i);
                node=node->link[1-bit];
                }
                else
                node=node->link[bit];
         }

        return ans;
    }
};
class oQc{
    public:
    int val;
    int x; 
    int ind;
    oQc(int val,int x,int ind){
        this->val=val;
        this->x=x;
        this->ind=ind;
    }
};
bool cmp(oQc &obj1,oQc&obj2){
    return obj1.val<obj2.val;
}
#define arr nums
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=nums.size();
        vector<oQc> oQ;
        sort(nums.begin(),nums.end());
        int i=0;
        for(auto &query: queries){
            oQc obj(query[1],query[0],i);
            i++;
            oQ.push_back(obj);
        }
        sort(oQ.begin(),oQ.end(),cmp);
        Trie T;
        int index=0;
        vector<int> fans(q,-1);
        for(auto a: oQ){
            while(index<n&&arr[index]<=a.val){
                T.insert(arr[index]);index++;
            }
            if(index!=0)
            fans[a.ind]=(T.max_xor(a.x));
        }
        return fans;
    }
};