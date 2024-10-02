class Solution {
public:
 int lcs(string s1,string s2){
        int m=s1.size();
        int n=s2.size();
        string ans="";
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        return lcs(s,rev);   
    }

};