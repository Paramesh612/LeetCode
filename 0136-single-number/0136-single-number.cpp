class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &x:nums){
            if(s.find(x)==s.end())s.insert(x);
            else s.erase(x);
        }
        for(auto &x:s) return x;
        return -1;
    }
};