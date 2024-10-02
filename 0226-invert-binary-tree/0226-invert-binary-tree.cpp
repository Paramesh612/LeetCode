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
    void build(TreeNode* root1,TreeNode* &dup ){
        if(!root1) return;
        dup=new TreeNode(root1->val);
        build( root1->left , dup->right );
        build( root1->right , dup->left );
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode *node=NULL;

        build(root,node);
        return node;
    }
};