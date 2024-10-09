/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* root1, TreeNode* root2, TreeNode* target) {
        if(root1==NULL) return NULL;
        
        if(root1==target) return root2;

        TreeNode *left = getTargetCopy(root1->left,root2->left,target);
        TreeNode *right = getTargetCopy(root1->right,root2->right,target);
        
        if(left!=NULL) return left;
        // if(right!=NULL) 
        return right;

    }
};