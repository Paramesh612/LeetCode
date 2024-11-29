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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int> ans;
        
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int maxx=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode *current = q.front();
                q.pop();

                maxx=max(maxx,current->val);

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};