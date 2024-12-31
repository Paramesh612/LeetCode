class Solution {
private:
    bool isPermitted(string a,string b){
        bool ret = false;
        for(int i=0; i<a.size(); i++){
            if(a[i]-b[i]){ 
                if(ret) return false; 
                else ret = true;
            }
        }
        return ret;
    }

    int BFS(vector<vector<int>> graph , int start , int end){
        queue<pair<int,int>> q; //Node , dist from start
        q.push({start,0});

        vector<int> visited(graph.size());
        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();
            
            for(auto &neighbor:graph[current.first] ){
                if(!visited[neighbor]){
                    if(neighbor == end) return current.second+1;
                    visited[neighbor] = true;
                    q.push({neighbor,current.second+1});
                }
            }
        }
        return -1;
    }
public:
    // Graph & BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;

        int n = wordList.size() , startNode = -1, endNode = -1 ;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord){
                startNode = i;
            }
            if(wordList[i]==endWord){
                endNode = i;
            }
            if(startNode!=-1 && endNode!=-1) break;
        }
        if(startNode==-1){ 
            wordList.push_back(beginWord);
            startNode = n;
            n++;
        }

        vector<vector<int>> graph(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n ; j++){
                if(isPermitted(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        return BFS(graph, startNode , endNode) + 1;
    }   
};