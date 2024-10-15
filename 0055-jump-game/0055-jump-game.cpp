class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);
        dp[0]=true;
        int i=0;
        int step = nums[i];
        for(i=1;i<n && step>0;i++){
            step--;
            step=max(nums[i],step);
            dp[i]=true; 
        }
        for(auto x:dp){
            cout<<x<<" ";
        }
        return dp[n-1];
    }
};