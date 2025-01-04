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

private:
    void inorder(TreeNode *root , int col , map<int,vector<int>> &mp){
        if(!root) return;
        inorder(root->left, col-1 , mp);
        mp[col].push_back(root->val);
        inorder(root->right, col+1 , mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>> mp;  // Col , ( row , val )
        vector<vector<int>> ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        int row = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n ; i++){
                auto current = q.front();
                q.pop();
                cout<<current.first->val<<" ";
                mp[current.second].insert({row,current.first->val});

                if(current.first->left) q.push({current.first->left,current.second-1});
                if(current.first->right) q.push({current.first->right,current.second+1});
                
            } 
            row++;
        }

        for(auto &x:mp){
            vector<int> temp;
            for(auto &el : x.second) temp.push_back(el.second);
            ans.push_back(temp);
        }
        return ans;
    }
};