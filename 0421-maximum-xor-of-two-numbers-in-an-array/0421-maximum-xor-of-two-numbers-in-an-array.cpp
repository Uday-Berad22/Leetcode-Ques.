class Node {
    Node* links[2];

public:
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    void put(int i, Node* node) {
        links[i] = node;
    }

    bool isContains(int i) {
        return (links[i] != nullptr);
    }

    Node* getLink(int i) {
        return links[i];
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {   
        Node * root =new Node;
        int N=arr.size();
        for(int i=0;i<N;i++){
            Node * node=root;
            for(int j=31;j>=0;j--){
                int x=((arr[i]>>j)&1);
                if(node!=NULL){
                node->isContains(x);
                if(node->isContains(x)==false){
                    Node *nn=new Node;
                    node->put(x,nn);
                }
                node=node->getLink(x);
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            Node * node=root;
            int temp=arr[i];
            for(int j=31;j>=0;j--){
                int x=((temp>>j)&1);
                if(x==0){
                    if(node->isContains(1)){
                        temp=temp|(1<<j);
                        node=node->getLink(1);
                    }
                    else{
                        node=node->getLink(0);
                    }
                }
                else if(x==1){
                     if(node->isContains(0)){
                        temp=temp|(1<<j);
                        node=node->getLink(0);
                     }
                     else{
                        temp=temp&(~(1<<j));
                        node=node->getLink(1);
                     }
                }
                
                
            }
            ans=max(ans,temp);
        }
        return ans;
    }

};