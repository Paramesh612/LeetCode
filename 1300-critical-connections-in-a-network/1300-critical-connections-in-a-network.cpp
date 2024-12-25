class Solution {
private:
    vector<vector<int>> makeGraph( int numNodes, vector<vector<int>> &edges ){
        vector<vector<int>> f(numNodes);
        for(auto &x:edges){
            f[x[0]].push_back(x[1]);
            f[x[1]].push_back(x[0]);
        }
        return f;
    }
    
    void solution(  vector<vector<int>> &graph, 
                    int currentNode, 
                    int parent, /*caller*/
                    vector<bool> &visited,
                    vector<int> &step, /*At which step its reached*/
                    vector<int> &low,
                    int &currentStep,
                    vector<vector<int>> &bridges
                 ){
        visited[currentNode] = true;
        step[currentNode] = currentStep++;
        low[currentNode] = step[currentNode];
        for(auto &neighbor : graph[currentNode]){
            if(!visited[neighbor]){
                solution(graph , neighbor, currentNode, visited , step, low, currentStep, bridges);
                
                /*
                    Do 2 stuff after returning from the neighbor:
                        1. Update the currentNode's low for future reference
                        2. Check if (currentNode - neighbor) link is a bridge

                        But (2) how?
                        If the low[neighbor] is greater than the step[currentNode]
                            it means that the ONLY way to get to neighbor is thru currentNode,
                            which means that the link is a bridge :)
                            
                            coz if it not had been a bridge, then its low value would have been
                            updated by some other earlier node ( than currentNode )
                */
                low[currentNode] = min( low[currentNode] , low[neighbor] );
                if(low[neighbor] > step[currentNode]) bridges.push_back({currentNode,neighbor});
            }else{
                if(neighbor != parent) low[currentNode] = min( low[currentNode] , low[neighbor] );
            }
        } 
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> 
            graph=makeGraph(n,connections), 
            bridges;

        vector<bool> visited(n,false);
        vector<int>
            step(n,-1),
            low(n,-1);
        
        int currentStep = 1;
        solution(graph , 0 , -1 , visited , step, low, currentStep, bridges);
        return bridges;
    }
};