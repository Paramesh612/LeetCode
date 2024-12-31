class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end() );
        queue<pair<string,int>> q; // For Level-Order or BFS

        q.push({beginWord,1});
        st.erase(beginWord); 
       
        while(!q.empty()){
            pair<string,int> curr = q.front();
            q.pop();
            

            for(auto &x:curr.first){
                char temp = x;
                for(char a = 'a' ; a<='z' ; a++){
                    x = a;
                    if(st.contains(curr.first)){
                        if(curr.first == endWord) return curr.second+1; // Parent level + 1
                        q.push({curr.first,curr.second+1});
                        st.erase(curr.first);
                    }
                }
                x = temp;
            }
        }
        
        return 0;
    }   
};