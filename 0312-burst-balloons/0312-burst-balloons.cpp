class Solution {
private:
// Print vector
    template <typename T>
    void println(vector<T> nums){
        for(auto &x:nums) cout<<x<<" ";
        cout<<endl;
    }

    int mul(vector<int>& nums , int a, int b, int c){
        int valA = ( a<0 || a>=nums.size() )? 1: nums[a];
        int valB = ( b<0 || b>=nums.size() )? 1: nums[b];
        int valC = ( c<0 || c>=nums.size() )? 1: nums[c];
        return valA*valB*valC;
    }
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
        for(auto &x:dp) println(x);
        return dp[1][n];
    }
};