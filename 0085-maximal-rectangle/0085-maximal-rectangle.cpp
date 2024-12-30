class Solution {
private:
    int findMaxAreaHistogram(vector<int> &height){
        int n=height.size();
        stack<int> mono; 
        mono.push(-1);
        int ans = 0;
        for(int i=0; i<=n ; i++){
            while(mono.top()!=-1 && (i==n || height[mono.top()]>= height[i]) ){
                // NextSmaller of mono.top() is i; prevSmaller is below it
                int currentTopIndex = mono.top();
                mono.pop();

                ans = max(ans, ((i-1) - (mono.top()+1) + 1)*(height[currentTopIndex]) );
            }
            mono.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size() , n = mat[0].size();   // m rows , n cols
        vector<vector<int>> matrix(m,vector<int>(n));

        for(int i=0;i<n;i++) matrix[0][i] = mat[0][i]-'0';
        for(int i=1; i<m ; i++){
            for(int j=0; j<n ; j++){
                if(mat[i][j]-'0'){
                    matrix[i][j] = (mat[i][j]-'0'+matrix[i-1][j]); 
                }
            }
        }

        // Now each Row is its own Histogram
        int ans = 0;
        // for(int i=0; i<m ; i++) println(matrix[i]);

        for(int i=0; i<m ; i++){
            ans = max(ans, findMaxAreaHistogram(matrix[i]));
        } 
        return ans;
    }
};