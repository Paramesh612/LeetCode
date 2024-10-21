class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        unordered_set<int> ans;
        for(auto &x:nums1){
            if(s2.find(x)!=s2.end()) ans.insert(x);
        }
        vector<int> v(ans.begin(),ans.end());
        return v;
    }
};