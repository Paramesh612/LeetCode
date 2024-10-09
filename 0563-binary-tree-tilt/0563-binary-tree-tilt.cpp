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

    int TreeSum(TreeNode *root , int &ans){
        if(!root) return 0;

        int leftSum = TreeSum(root->left , ans);
        int rightSum = TreeSum(root->right , ans);

        ans+=abs(leftSum-rightSum);
        return root->val + leftSum + rightSum ;
    }

    int findTilt(TreeNode* root) {
        int ans=0;
        TreeSum(root,ans);

        return ans;
    }
};