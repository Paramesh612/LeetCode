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
    bool findTarget(TreeNode* root, int target) {
        stack<TreeNode*> forwardStack , reverseStack;
        TreeNode *left = root , *right = root;
        while((left || !forwardStack.empty()) && (right || !reverseStack.empty())){

            while(left){
                forwardStack.push(left);
                left = left->left;
            }

            while(right){
                reverseStack.push(right);
                right = right->right;
            }

            if(reverseStack.empty() || forwardStack.empty()) return false;
            
            left = forwardStack.top();
            right = reverseStack.top();

            if(left->val > right->val) return false;

            if(left->val + right->val == target) return left == right?false:true;
            else if(left->val + right->val > target) {
                reverseStack.pop();
                right = right->left;
                left = nullptr;
            }else{ 
                left = left->right;
                right = nullptr;
                forwardStack.pop();
            }
        }
        return false;
    }
};