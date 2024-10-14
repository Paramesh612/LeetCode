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
    void inorder(TreeNode *root ,  TreeNode *&prev , TreeNode* &head){
        if(!root) return;
        inorder(root->left ,  prev , head);
        if(!prev) {prev=root;head=root;}
        else{
            prev->left=NULL;
            prev->right=new TreeNode(root->val);
            prev=prev->right;
        }
        inorder(root->right , prev , head);
    }   

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *head=NULL ,*prev=NULL;
        inorder(root,prev,head);
        return head;
    }
};