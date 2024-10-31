class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxx=INT_MIN ,count=0;
        for(auto &x:nums){
            mp[x]++;
            maxx=max(maxx,mp[x]);
        }

        for(auto &x:mp)if(maxx==x.second)count++;
        return count*maxx;
    }
};