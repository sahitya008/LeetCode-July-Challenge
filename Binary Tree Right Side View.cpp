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
    int level=0;
    void modify(vector<int> &ans,int level, TreeNode* root){
        if(!root) return;
        if(level==ans.size())
            ans.push_back(root->val);
        if(root->right)
            modify(ans,level+1,root->right);
        if(root->left)
            modify(ans,level+1,root->left);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
        modify(ans,0,root);
        return ans;
    }
};