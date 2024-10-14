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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int n = q.size();
            bool foundX=false , foundY=false;

            for(int i=0;i<n;i++){
                TreeNode *current = q.front();
                q.pop();
                if(current->val == x) foundX=true;
                if(current->val == y) foundY=true;

                if(current->left!=NULL && current->right!=NULL){
                    if((current->left->val==x && current->right->val==y)||(current->left->val==y && current->right->val==x)) 
                        return false;

                    q.push(current->left);
                    q.push(current->right);
                }
                else if(current->left) q.push(current->left);
                else if(current->right) q.push(current->right);
            }
            if(foundX && foundY) return true;
        }
        return false;
    }
};