/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& mp, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd || preIndex>=preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int i = mp[preorder[preIndex++]];
        root->left = helper(preorder, mp, preIndex, inStart, i - 1);
        root->right = helper(preorder, mp, preIndex, i + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        return helper(preorder, mp, preIndex, 0, inorder.size() - 1);
    }
};