class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index ,pair<int,int>pos/*Row,Col*/,vector<vector<bool>> &visited){ 
        if(pos.first<0 || pos.first>=board.size() || pos.second<0 || pos.second>=board[0].size() ) return false;
        if(visited[pos.first][pos.second] || board[pos.first][pos.second]!=word[index]) return false;
        if(index==word.size()-1) return true;

        visited[pos.first][pos.second]=true;
        bool ret= (dfs(board,word,index+1,make_pair(pos.first+1,pos.second),visited) ||
                    dfs(board,word,index+1,make_pair(pos.first-1,pos.second),visited) ||
                    dfs(board,word,index+1,make_pair(pos.first,pos.second+1),visited) ||
                    dfs(board,word,index+1,make_pair(pos.first,pos.second-1),visited));
        visited[pos.first][pos.second]=false;
        return ret;

        
        

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        bool ret=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]) ret = dfs(board,word,0,make_pair(i,j),visited);
                if(ret) return true;
            }
        } 
        return ret;
    }

};