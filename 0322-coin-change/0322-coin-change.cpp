class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;

        int m=coins.size(); // Rows
        int n=amount+1; //Cols

        // vector<vector<int>> dp(m,vector<int>(n,INT_MAX));

        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        int minn=INT_MAX;

        // sort(coins.begin(),coins.end());

        for(int i=0;i<m;i++){
            for(int j=coins[i];j<n;j++){
                if(dp[j-coins[i]]!=INT_MAX)
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);

            }
        }


        if(dp[n-1]==INT_MAX) return -1;
        return dp[n-1];
    }
};