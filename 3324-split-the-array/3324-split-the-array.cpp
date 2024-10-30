class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_set<int> s1,s2;
        for(auto &x:nums){
            if(s1.find(x)==s1.end()) s1.insert(x);
            else if(s2.find(x)==s2.end()) s2.insert(x);
            else return false;
        }
        return true;
    }
};