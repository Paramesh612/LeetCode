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
    void inorder(TreeNode* root, int targetSum , int sum ,vector<int>&temp, vector<vector<int>>&ans){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            if(targetSum==sum+root->val) ans.push_back(temp); //if(ans.empty() || ans.back()!=temp)
            temp.pop_back();
            return;
        }

        temp.push_back(root->val);

        inorder(root->left,targetSum,sum+root->val,temp,ans);
        inorder(root->right,targetSum,sum+root->val,temp,ans);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int>temp;
        vector<vector<int>>ans;
        inorder(root,targetSum,0,temp,ans);
        return ans;
    }
};