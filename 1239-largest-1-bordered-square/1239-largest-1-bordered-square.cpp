class Solution {
public:
// Print vector
    template <typename T>
    void println(vector<T> arr){
        for(auto &x:arr) cout<<x<<" ";
        cout<< " - " ;
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m+2, (vector<vector<int>>(n+2,vector<int>(4,0))));

        // Up , down , left , right 

        // Left , Up
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]){
                    dp[i][j][0] = grid[i-1][j-1] + dp[i-1][j][0]; // Up
                    dp[i][j][2] = grid[i-1][j-1] + dp[i][j-1][2]; // Left
                }
                int x = m-i+1 , y = n - j + 1;
                if(grid[x-1][y-1]){
                    dp[x][y][1] = grid[x-1][y-1] + dp[x+1][y][1]; // Down
                    dp[x][y][3] = grid[x-1][y-1] + dp[x][y+1][3]; // Right
                }
            }
        }
        
        for(auto &x:dp){
            for(auto &el:x) println(el);
            cout<<endl;
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int nowUp = dp[i][j][0];
                int nowLeft = dp[i][j][2];
                printf("For i=%d,j=%d --> checking => ",i,j);
                for(int x = 0; grid[i-1][j-1] && x<min(dp[i][j][0] , dp[i][j][2]) ; x++ ){
                    printf("(%d,%d) - ",i-x,j-x);
                    int candidateDown = dp[i-x][j-x][1];
                    int candidateRight = dp[i-x][j-x][3];

                    if(candidateDown>=x && nowUp>=x && nowLeft >=x && candidateRight>=x) {
                        ans = max(
                            ans,
                            (x+1)*(x+1)
                        );
                        cout<<"maximaxi set to "<<ans<<", ";
                    }
                }
                cout<<endl;
            }
        }
        return ans;
    }
};