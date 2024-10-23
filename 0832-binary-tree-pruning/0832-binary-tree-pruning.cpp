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
    bool traverse(TreeNode *&root){
        if(!root) return false;

        bool leftHas = traverse(root->left);
        bool rightHas = traverse(root->right);
        if(!leftHas) root->left=NULL;
        if(!rightHas) root->right=NULL;

        return leftHas || rightHas || root->val==1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        traverse(root);
        if(!root->left && !root->right && root->val==0) return NULL;
        return root;

    }
};