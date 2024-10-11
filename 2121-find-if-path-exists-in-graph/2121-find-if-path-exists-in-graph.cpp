class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, int node, int dest , vector<bool>&visited){
        if(node == dest) return true;
        if(visited[node]) return false;

        visited[node]=true;
        for(int i:adjList[node]){
            if(dfs(adjList,i,dest,visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n,vector<int>());
        for(auto &x:edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        return dfs(v,source,destination,visited);
    }
};