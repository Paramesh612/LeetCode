class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 , 0);
        const long long MOD = 1000000007;     
        int ans = 0;
        dp[0]=1;
        for(int i=1;i<=high;i++){
            if(i-zero>=0) dp[i]=(dp[i]+dp[i-zero])%MOD;
            if(i-one>=0) dp[i]=(dp[i]+dp[i-one])%MOD;

            if(i>=low) ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};