class Solution {
public:
    void reverse(vector<vector<int>>& grid , int start, int end){
        while(start<end){
            int rowStart = start/grid[0].size();
            int colStart = start%grid[0].size();


            int rowEnd = end/grid[0].size();
            int colEnd = end%grid[0].size();

            swap(grid[rowStart][colStart],grid[rowEnd][colEnd]);
            start++;
            end--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n=grid[0].size();
        k%=(m*n);
        if(k==0) return grid;
        int pivot = m*n - k;

        reverse(grid , 0, pivot-1);
        reverse(grid , pivot , m*n-1);
        reverse(grid , 0 , m*n-1);
        
        return grid;
    }
};