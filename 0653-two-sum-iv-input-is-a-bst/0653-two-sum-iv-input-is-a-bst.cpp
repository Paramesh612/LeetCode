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
    void inorder(TreeNode *root , unordered_set<int> &st, int &target ,bool &ans){
        if(!root || ans) return ;
        inorder(root->left , st, target , ans);
        if(st.contains(target - root->val)){
            ans = true;
            return;
        }
        st.insert(root->val);
        inorder(root->right , st, target , ans);

    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        bool ans = false;
        inorder(root , st, k , ans);
        return ans;

    }
};