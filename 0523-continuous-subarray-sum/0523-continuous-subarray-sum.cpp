class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() , remPrefix = 0;
        unordered_map<int,int> remMap;
        remMap[0] = -1;
        
        for(int i=0; i<n; i++){
            remPrefix = (remPrefix+nums[i])%k;
            if((remMap.contains(remPrefix) && i-remMap[remPrefix]>1 )) return true;
            if(!remMap.contains(remPrefix)) remMap[remPrefix] = i;
        }
        return false;
    }
};