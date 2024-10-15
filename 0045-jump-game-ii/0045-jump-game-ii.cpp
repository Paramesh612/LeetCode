class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,INT_MAX-100); 

        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=n-1) dp[i]=1;
            else{
                for(int j=1; j<=nums[i] ;j++){
                    dp[i]=min(dp[i+j],dp[i]);
                }
                dp[i]+=1;
            } 
            // dp[i]=dp[i+nums[i]]+1;
        }   

        return dp[0];
    }
};