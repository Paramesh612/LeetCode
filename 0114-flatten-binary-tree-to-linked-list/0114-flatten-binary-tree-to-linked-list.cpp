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
    // void helper2(TreeNode *&root,TreeNode *&prev){
    //     if(!prev) prev=root;
    //     if(!root) return;
        
    //     prev->right=root;
    //     prev->left=NULL;
    //     prev=root;
    //     TreeNode* newRight = helper2(root->left,prev);
        
    // }

    TreeNode* helper(TreeNode *&root){
        if(!root) return root;

        TreeNode* newRight=helper(root->left);
        root->left=NULL;

        TreeNode* newRight2=helper(root->right);

        root->right=newRight;
        TreeNode *tr=root;
        while(tr->right!=NULL) tr=tr->right;

        tr->right = newRight2;
        root->left=NULL;

        return root;
    }
    void flatten(TreeNode* root) {
        root=helper(root);
    }
};