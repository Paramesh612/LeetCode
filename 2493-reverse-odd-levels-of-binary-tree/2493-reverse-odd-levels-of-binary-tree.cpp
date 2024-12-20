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

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        stack<int>st;
        list<TreeNode*> NodeList;
        NodeList.push_back(root);
        st.push(root->val);
        int level=0;
        while(!NodeList.empty()){
            if(level&1){
                for(auto &x:NodeList){
                    x->val = st.top();
                    st.pop();
                }
            }

            int n = NodeList.size();
            for(int i=0; i<n ; i++){
                TreeNode *current = NodeList.front();
                NodeList.pop_front();

                if(current->left){
                    NodeList.push_back(current->left);
                    st.push(current->left->val);
                    NodeList.push_back(current->right);
                    st.push(current->right->val);
                }

            }

            level++;
        }
        return root;
    }
};