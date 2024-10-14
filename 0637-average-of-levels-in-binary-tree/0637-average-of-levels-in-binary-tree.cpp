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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;

        vector<double> ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            // cout<<"n = "<<n<<endl;
            double sum=0.0;
            for(int i=0; i<n ; i++){
                auto current = q.front();
                q.pop();
                sum+=current->val;

                if(current->left) {
                    // cout<<"current->left->val : "<<current->left->val;
                    q.push(current->left);
                }
                if(current->right) q.push(current->right);
            }

            // cout<<"q.size() = "<<q.size()<<endl;

            ans.push_back(sum/((double)n));
        }
        return ans;
    }
};