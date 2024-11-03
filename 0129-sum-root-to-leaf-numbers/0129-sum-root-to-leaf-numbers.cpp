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

    void helper(TreeNode *root, long long temp ,int &sum){
        if(!root->left && !root->right) sum+=(root->val+temp);

        temp+=root->val;
        temp*=10;

        if(root->left) helper(root->left,temp,sum);
        if(root->right) helper(root->right,temp,sum);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        helper(root , 0, sum);    
        return sum;
    }
};