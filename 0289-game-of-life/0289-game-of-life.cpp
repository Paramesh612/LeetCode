class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> toDie , toAlive;

        vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                int countAlive=0;
                for(int k=0;k<dir.size();k++){
                    int neighborRow = i+dir[k].first;
                    int neighborCol = j+dir[k].second;
                    if(neighborRow>=0 && neighborCol>=0 && neighborRow<board.size() && neighborCol<board[0].size() ){
                        if(board[neighborRow][neighborCol]) countAlive++;
                    }
                }

                if(board[i][j]==1){
                    if(countAlive<2 || countAlive>3) toDie.push_back({i,j});
                }
                else{
                    if(countAlive==3) toAlive.push_back({i,j});
                }
            }
        }

        for(auto &x:toDie){
            board[x.first][x.second]=0;
        }
        
        for(auto &x:toAlive){
            board[x.first][x.second]=1;
        }
    }
};