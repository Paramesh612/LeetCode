class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    board[i][j]='.';
                    if( dfsRight(board,i,j+1) ) 1;
                    else if ( dfsDown(board,i+1,j) ) 1 ;
                    count++;
                }
            }
        }
        return count;
    }

    bool dfsRight(vector<vector<char>>& board ,int i ,int j){
        if(i>=board.size() || j>=board[0].size() || board[i][j]=='.') return false;

        board[i][j]='.';
        dfsRight(board, i,j+1);
        return true;
    }

    bool dfsDown (vector<vector<char>>& board ,int i ,int j){
        if(i>=board.size() || j>=board[0].size() || board[i][j]=='.') return false;

        board[i][j]='.';
        dfsDown(board , i+1,j);
        return true;
    }
};