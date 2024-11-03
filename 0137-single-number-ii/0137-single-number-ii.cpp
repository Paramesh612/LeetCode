class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &x:nums){
            mp[x]++;
            if(mp[x]==3) mp.erase(x);
        }

        return mp.begin()->first;
    }        
};