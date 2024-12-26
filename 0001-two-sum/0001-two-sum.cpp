class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mp;  // val , index
        for(int i=0;i<arr.size();i++){ if(mp.find(target-arr[i])!=mp.end() && i!=mp[target-arr[i]]) return {i,mp[target-arr[i]]}; mp[arr[i]]=i;}
        return {-1,-1};
    }
};