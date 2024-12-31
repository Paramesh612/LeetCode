class Solution {
public:
/*
    Graph & BFS ( Damn )
    This is Good. Really good. But its O(n^2 k); n -> number of words , k-> length of word
    You can use the generating word combos and then making a hashmap ( pattern -> word )
    And then directly use that for BFS. Like everytime you need a neighbor , you generate the pattern
    then look in the map , traverse the neighbors. 
    I don't think it changes the O() value . But it might change the runtime
    Check out neetcode for that method
*/

    // Then there's the GOAT. Striver. Who did it in O(nklogn); [ O(nk) if you use a hashset instead of set ]
    // This man really converted this to a TREE & Level-order(BFS)  --> O( wordLength*26*n )

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end() );
        queue<pair<string,int>> q; // For Level-Order or BFS

        q.push({beginWord,1});
        st.erase(beginWord); 
        // Because its visited. Visiting later only means same or LATER level. Why would I take it if I can reach now

        // Since I'm using Level-Order, the first time that we see the string will be the ans/
        // Later means , it ONLY has a possibility of being in same or GREATER level

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
                        // Because its visited. Visiting later only means same or LATER level. Why would I take it if I can reach now
                    }
                }
                x = temp;
            }
        }
        
        return 0;
    }   
};