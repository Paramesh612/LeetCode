class Solution {
public:

    // int numTrees(int n){

    //     return numTrees(numNodes-1)*numTrees(n-numNodes);
    //     // numNodes = numNodes(numNodes-1);

    // }

    int soln(int n , unordered_map<int,int>&mp){
        if(mp.find(n)!=mp.end()) return mp[n];

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(soln(i,mp)*soln(n-i-1,mp));
        }
        mp[n]=ans;
        return ans;
    }
    int numTrees(int n) {
        unordered_map<int,int>mp;
        mp[0]=1;
        // mp[1]=1;
        // mp[2]=2;
        // mp[3]=5;

        return soln(n,mp);
    }
};