class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxx=INT_MIN ,count=0;
        for(auto &x:nums){
            mp[x]++;
            if(mp[x]>maxx){
                count=1;
                maxx=mp[x];
            }else if(maxx==mp[x]) count++;
        }
        return count*maxx;
    }
};