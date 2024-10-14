/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void inorder(Node* root, int h, int &maxh){
        if(!root) return;

        maxh=max(h,maxh);

        for(auto &x:root->children){
            inorder(x , h+1 , maxh);
        }

    }
    int maxDepth(Node* root) {
        int maxh=0;
        inorder(root, 1 , maxh);
        return maxh;
    }   
};