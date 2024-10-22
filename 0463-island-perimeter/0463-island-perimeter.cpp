class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row, int col , vector<vector<bool>>&visited , int &ans){
        visited[row][col]=true;
        vector<pair<int,int>> v={{-1,0},{+1,0},{0,-1},{0,+1}};
        
        // for(int i=0;i<4;i++)
        for(auto &x:v){
            int newRow = row+x.first;
            int newCol = col+x.second;

            if(newRow<0 || newRow>=grid.size() || newCol<0 || newCol>=grid[0].size() ){
                ans++;
                continue;
            }

            if(grid[newRow][newCol] == 0) ans++;

            if(!visited[newRow][newCol] && grid[newRow][newCol]) dfs(grid,newRow,newCol,visited,ans);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    dfs(grid,i,j,visited,ans);
                    return ans;
                }
            }
        }
        return ans;
    }
};