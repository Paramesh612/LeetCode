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
public:                                                         //Starts at 2
    void helper(TreeNode* &root, int val, int targetDepth , int currentDepth){
        if(!root) return;

        if(targetDepth==currentDepth){
            TreeNode* tempLeft = new TreeNode(val,root->left,NULL);
            TreeNode* tempRight = new TreeNode(val,NULL,root->right);

            root->left = tempLeft;
            root->right = tempRight;

            return; 
        }

        helper(root->left , val , targetDepth , currentDepth+1);
        helper(root->right, val , targetDepth , currentDepth+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode *newRoot = new TreeNode(val,root,NULL); 
            return newRoot;
        } 

        helper(root , val , depth , 2);
        return root;
    }
};