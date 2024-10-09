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
    void inorder(TreeNode *root, unordered_map<int , int> &mp ){
        if(!root) return;
        mp[root->val]++;
        inorder(root->left,mp);
        inorder(root->right,mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int> mp;
        inorder(root , mp);
        vector<int> ans;

        int maxValue=INT_MIN;

        for(auto &x:mp){
            if(x.second>=maxValue) maxValue = x.second;
        }

        for(auto &x:mp){
            if(x.second == maxValue) ans.push_back(x.first);
        }

        return ans;
    }
};