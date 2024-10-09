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
    void inorder(TreeNode *root, int &count , long &minn ,long &secondMin){
        // cout<<"Min: "<<minn<<"  SecondMIN: "<<secondMin<<endl;
        // cout<<"Count:  "<<count<<endl;
        if(!root ) return; //|| count>=2

        if(root->val<minn) { //&& count<2
            secondMin = minn;
            minn = root->val;
            // count++;
        }else if(root->val > minn && root->val < secondMin) secondMin=root->val;

        inorder(root->left , count, minn,secondMin);
        inorder(root->right , count, minn , secondMin);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long secondMin=LONG_MAX, minn=LONG_MAX;
        int count=0;
        
        inorder(root , count, minn , secondMin);
        // cout<<"Count Main:  "<<count;
        if(minn!=secondMin && minn!=LONG_MAX && secondMin!=LONG_MAX) return secondMin;
        return -1;
    }
};