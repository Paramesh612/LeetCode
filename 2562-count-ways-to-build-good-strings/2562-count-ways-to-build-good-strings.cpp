class Solution {
private:
    void rec( string temp , int &ans, string &zeroString , string &oneString, int low , int high){
        if(temp.size() > high) return;
        if(temp.size() >= low ) ans++;
        
        rec(temp+zeroString, ans, zeroString , oneString, low, high);
        rec(temp+oneString, ans, zeroString , oneString, low, high);
    }
public:
    int countGoodStrings____Rec(int low, int high, int zero, int one) {
        const long long MOD = 1000000007;     
        string zeroString(zero,'0') , oneString(one,'1');
        int ans=0;
        rec("" , ans , zeroString, oneString , low , high);
        return ans%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 , 0);
        const long long MOD = 1000000007;     
        long long ans = 0;

        dp[0]=1;
        for(int i=1;i<=high;i++){
            if(i-zero>=0) dp[i]=(dp[i]+dp[i-zero]%MOD);
            if(i-one>=0) dp[i]=(dp[i]+dp[i-one]%MOD);

            if(i>=low) ans=(ans+dp[i])%MOD;
        }
        return ans%MOD;
    }
};