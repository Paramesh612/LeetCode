class Solution {
    public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int len = 0 ; len < n ; len++){
            for(int i=1; i<=n-len; i++){
                int j = len + i;
                for(int k=i; k<=j ; k++ ){
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k-1]+dp[k+1][j]+ nums[i-1]*nums[k]*nums[j+1]
                    );
                }
            }
        }
        return dp[1][n];
    }
};