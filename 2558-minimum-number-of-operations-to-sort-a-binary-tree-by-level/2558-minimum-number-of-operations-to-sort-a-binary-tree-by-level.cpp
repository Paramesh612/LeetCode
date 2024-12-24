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
    int findMinSwaps(vector<pair<int,int>>& arr) {

        sort(arr.begin(),arr.end());
        
        int curr=0,count=0;
        while(curr<arr.size()){
            if(curr!=arr[curr].second){
                swap(arr[curr],arr[arr[curr].second]);
                count++;
            }
            else 
                curr++;
        }
        
        return count;
        
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;

        while(!q.empty()){
            int n = q.size();
            vector<pair<int,int>> arr;
            for(int i=0; i<n ; i++){
                auto current = q.front();
                arr.push_back({current->val,i});
                q.pop();

                if(current -> left) q.push(current -> left);
                if(current -> right) q.push(current -> right);
            }

            count+= findMinSwaps(arr);

        }    
        return count;
    }
};