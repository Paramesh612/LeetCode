/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;

        mp[node]=new Node(node->val);
        q.push(node);

        while(!q.empty()){  
            Node* current=q.front();
            q.pop();
            for(auto x:current->neighbors){
                if(mp.find(x)==mp.end()){ 
                    mp[x]=new Node(x->val);
                    q.push(x);
                }
                mp[current]->neighbors.push_back(mp[x]);
            }
        }
        return mp[node];
    }
};