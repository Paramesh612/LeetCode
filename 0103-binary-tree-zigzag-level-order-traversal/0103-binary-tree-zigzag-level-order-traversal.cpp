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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        // int j=0;

        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode *current=q.front();
                q.pop();
                temp.push_back(current->val);

                if(current->left!=NULL)
                    q.push(current->left);
                if(current->right!=NULL)
                    q.push(current->right);
            }
            //if(j%2==0)
                // reverse(temp.begin() , temp.end());
            ans.push_back(temp);
            // j++;
        }

        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin() , ans[i].end());
        }

        return ans;
    }
};