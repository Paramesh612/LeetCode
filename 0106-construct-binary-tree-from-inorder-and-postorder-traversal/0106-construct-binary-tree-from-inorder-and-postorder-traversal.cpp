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
    TreeNode* helper(vector<int>& postorder , unordered_map<int,int> &inMap , int inStart, int inEnd , int &postIndex){
        if(postIndex<0 || inStart>inEnd) return nullptr;

        int rootVal = postorder[postIndex];
        postIndex--;
        int index = inMap[rootVal];

        TreeNode *root= new TreeNode(rootVal);
        root->right = helper(postorder , inMap , index+1 , inEnd , postIndex  );
        root->left = helper(postorder , inMap , inStart , index-1 , postIndex  );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int,int> inMap;
         for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
         }
         int postIndex=inorder.size()-1;
         return helper(postorder,inMap,0,inorder.size()-1,postIndex);
    }
};