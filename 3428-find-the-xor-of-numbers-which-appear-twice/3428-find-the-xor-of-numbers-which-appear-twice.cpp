class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans=0;
        unordered_set<int> s;
        for(auto &x:nums){
            if(s.count(x)) ans^=x;
            s.insert(x);
        }
        return ans;
    }
};