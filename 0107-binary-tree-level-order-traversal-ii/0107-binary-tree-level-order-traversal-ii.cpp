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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode *current = q.front();
                q.pop();

                if(current->left){
                    q.push(current->left);
                    temp.push_back(current->left->val);
                }

                
                if(current->right){
                    q.push(current->right);
                    temp.push_back(current->right->val);
                }

            }
            if(!temp.empty()) ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};