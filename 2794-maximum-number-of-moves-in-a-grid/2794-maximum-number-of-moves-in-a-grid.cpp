class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {   
        int m = grid.size() , n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<vector<int>> dir = {{-1,-1},{0,-1},{+1,-1}};
        int col;
        for(col=1;col<n; col++){
            bool flag=false;
            for(int row = 0; row<m ; row++){
                int maxVal=INT_MIN;
                for(auto &x:dir){
                    int checkRow = row+x[0];
                    int checkCol = col+x[1];
                    if(checkRow>=0 && checkCol>=0 && checkRow<grid.size() && checkCol<grid[0].size() && grid[row][col]>grid[checkRow][checkCol]){
                        if(dp[checkRow][checkCol]!=0 || checkCol==0){ 
                            dp[row][col] = max(dp[row][col] , 1 + dp[checkRow][checkCol]);
                        }else{
                            dp[row][col] = max(dp[row][col] , dp[checkRow][checkCol]);
                        }
                    }
                }
                if(dp[row][col]!=0)
                    flag=true;
            }
            if(!flag) break;
        }
        int maxx = INT_MIN;

        col--;
        
        for(int i=0;i<m ;i++){
            maxx=max(maxx,dp[i][col]);
        }

        return maxx;
    }
};