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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return helper(root,mp);
    }
    int helper(TreeNode* root,unordered_map<TreeNode*,int> &mp) {
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int val=root->val;
        if(root->right) val+=helper(root->right->left,mp)+helper(root->right->right,mp);
        if(root->left) val+=helper(root->left->left,mp)+helper(root->left->right,mp);

        mp[root]=max(val , helper(root->left,mp)+helper(root->right,mp));
        return mp[root];

    }
};