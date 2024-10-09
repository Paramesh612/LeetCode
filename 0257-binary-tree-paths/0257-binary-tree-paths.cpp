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
    void traverse(TreeNode *root , string str , vector<string> &ans){
        if(!root) {ans.push_back(str);return;}

        if(!root->left){
            if(!str.empty()) traverse(root->right , str+"->"+ to_string(root->val) , ans );
            else traverse(root->right , str+ to_string(root->val) , ans );
        }
        else if(!root->right){
            if(!str.empty()) traverse(root->left , str+"->"+ to_string(root->val) , ans );
            else traverse(root->left , str+ to_string(root->val) , ans );
        }else{

            if(!str.empty()) traverse(root->left , str+"->"+ to_string(root->val) , ans );
            else traverse(root->left , str+ to_string(root->val) , ans );
            if(!str.empty()) traverse(root->right , str+"->"+ to_string(root->val) , ans );
            else traverse(root->right , str+ to_string(root->val) , ans );

        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        traverse(root , "" , ans);
        return ans;
    }
};