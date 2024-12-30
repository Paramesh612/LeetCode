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
        int ans = 0;
        
        // Now each Row is its own Histogram
        vector<int>arr(n); // Using 1D vector to create a temp int array of the current row
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]-'0') arr[j]++;
                else arr[j]=0;
            }
            ans = max(ans, findMaxAreaHistogram(arr));
        } 
        return ans;
    }
};