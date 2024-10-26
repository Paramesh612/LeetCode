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
    // bool leftSubtree(TreeNode *root , int val){
    //     if(!root) return true;

    //     if(root->val>=val) return false;

    //     return (leftSubtree(root->left,root->val) && rightSubtree(root->right,root->val));
    // }

    // bool rightSubtree(TreeNode *root , int val){
    //     if(!root) return true;

    //     if(root->val<=val) return false;

    //     return (leftSubtree(root->left,root->val) && rightSubtree(root->right,root->val));
    // }
    
    bool inorder(TreeNode *root, TreeNode *&prev){
        if(!root) return true;
        bool left = inorder(root->left,prev);
        if(prev==NULL){
            prev=root;
        }else if(prev->val>=root->val){
            return false;
        }else{
            prev=root;
        }
        cout<<root->val;
        bool right = inorder(root->right,prev);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        // return (leftSubtree(root->left,root->val) && rightSubtree(root->right,root->val));
        TreeNode *prev=NULL;
        return inorder(root,prev);

    }
};