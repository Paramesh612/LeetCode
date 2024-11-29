/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        helper(root,target,k,ans);    
        return ans;
    }

    // isFound,k
    pair<bool,int> helper( TreeNode* root , TreeNode *target , int k , vector<int>&ans){
        if(!root) return {false,-1};

        if(root==target){
            dfs(root,ans,k);
            return {true,k-1};
        }

        auto left = helper(root->left, target , k , ans);
        auto right = helper(root->right, target , k , ans);

        if(left.first){
            if(left.second==0){
                ans.push_back(root->val);
            }else if(left.second>0){
                dfs(root->right,ans,left.second-1);
            }

            return {true,left.second-1};
        }else if(right.first){
            if(right.second==0){
                ans.push_back(root->val);
            }else if(right.second>0){
                dfs(root->left,ans,right.second-1);
            }

            return {true,right.second-1};
        }
        return {false,-1};
    }

    void dfs(TreeNode *root ,vector<int>& ans ,int k){
        if(!root) return;

        if(k==0){ 
            ans.push_back(root->val);
            return;
        }

        dfs(root->left,ans,k-1);
        dfs(root->right,ans,k-1);
    }
};