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
        vector<int> ans;
    void solve(TreeNode* root,int curr, int &maxl){
        if(root == NULL) return;
        if(curr > maxl){
            maxl = curr;
            ans.push_back(root->val);
        }

        ans[curr] = max(ans[curr],root->val);
        solve(root->left,curr + 1,maxl);
        solve(root->right,curr+1,maxl); 
    }

    vector<int> largestValues(TreeNode* root){
        int maxl = -1;
        solve(root,0,maxl);
        return ans;    
    }

};