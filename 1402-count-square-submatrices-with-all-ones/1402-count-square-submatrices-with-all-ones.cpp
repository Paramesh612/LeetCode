class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size() , n= matrix[0].size();
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && j>0 && matrix[i][j]){
                    matrix[i][j]= max(matrix[i][j],1+min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]}));
                }
                cnt+=matrix[i][j];
            }
        }
        return cnt;
    }
};

// auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();