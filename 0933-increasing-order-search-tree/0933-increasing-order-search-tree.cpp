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
    void inorder(TreeNode *root , vector<TreeNode*> &v){
        if(!root) return;

        inorder(root->left , v);
        v.push_back(root);
        inorder(root->right ,v);
    }   

    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root,v);

        TreeNode *temp=NULL;
        for(auto &x:v){
            cout<<x->val;

            if(!temp) temp=x;
            else{
                temp->left=NULL;
                // temp->right=x;
                temp->right= new TreeNode(x->val);
                temp=temp->right;
            }
        }
        return v[0];
    }
};