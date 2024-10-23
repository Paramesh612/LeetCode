/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode * left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*,long> mp;  // Parnt , childsum
        queue<pair<TreeNode*,TreeNode*>> q; //Node,Parent
        vector<int> levelSum;

        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            long sum=0;
            for(int i=0;i<n;i++){
                TreeNode *current = q.front().first;
                TreeNode *parent = q.front().second;
                q.pop();

                if(current->left!=NULL) q.push({current->left,current});
                if(current->right!=NULL) q.push({current->right,current});
                sum+=current->val;
                // if(parent!=NULL)
                mp[parent]+=current->val;

            }
            levelSum.push_back(sum);
        }

        //2nd traversal --> levelSum - myParent's childsum (ie my sibling sum);

        int level=0;
        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *current = q.front().first;
                TreeNode *parent = q.front().second;
                q.pop();
                current->val = levelSum[level]-mp[parent];
                if(current->left!=NULL) q.push({current->left,current});
                if(current->right!=NULL) q.push({current->right,current});

            }
            level++;
        }

        return root;

    }
};