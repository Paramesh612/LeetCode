/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int &prev, int &minn) {
        if(!root) return;
        inorder(root->left , prev , minn);
        if(prev==INT_MAX) prev=root->val;
        else{
            minn = min(minn, abs(prev-root->val));
            prev=root->val;
        }
        inorder(root->right, prev, minn);
        
        // if (!root->left && !root->right)
        //     return ;
        // if (root->right!=NULL) {
        //     minn = min(minn, abs(root->val - root->right->val));
        //     inorder(root->right,minn);
        // }
        // if(root->left!=NULL){
        //     minn = min(minn,abs(root->val - root->left->val));
        //     inorder(root->left,minn);
        // }
    }

    int getMinimumDifference(TreeNode* root) {
        int minn=INT_MAX, prev=INT_MAX;
        inorder(root,prev,minn);
        return minn;
    }
};