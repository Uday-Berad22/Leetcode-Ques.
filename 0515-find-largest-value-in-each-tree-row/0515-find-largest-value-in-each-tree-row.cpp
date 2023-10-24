/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> lv;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qsiz=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<qsiz;i++){
                TreeNode * p= q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
                maxi=max(maxi,p->val);
            }
            lv.push_back(maxi);
        }
        return lv;
    }
};