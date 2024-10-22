/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> sum;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            long long n=q.size();
            long long sumTemp=0;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();

                sumTemp+=curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            sum.push(sumTemp);
        }

        if(sum.size()<k) return -1;

        for(int i=0;i<k-1;i++){
            sum.pop();
        }

        return sum.top();
    }
};