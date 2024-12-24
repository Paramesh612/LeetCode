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
    TreeNode* sol(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        auto maxx = max_element(nums.begin()+start,nums.begin()+end+1);
        int maxIndex = maxx - nums.begin();
        TreeNode* root = new TreeNode(*maxx);

        if(maxx!=nums.begin()+start) root->left = sol(nums, start , maxIndex - 1);
        if(maxx!=nums.begin()+end) root->right = sol(nums, maxIndex + 1 , end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return sol(nums,0,nums.size()-1);
    }
};