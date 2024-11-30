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
    void preorder(TreeNode *root , int &sum, bool isLeft){
        if(!root) return;
        if(!root->left && !root->right && isLeft){ sum+=root->val; return; }

        preorder(root->left,sum , true);
        preorder(root->right,sum , false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        preorder(root,sum,false);
        return sum;
    }
};