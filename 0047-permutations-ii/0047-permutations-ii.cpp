class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<int>nums2=nums;
        do {
            st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));

        while(prev_permutation(nums2.begin(),nums2.end())){
            st.insert(nums2);
        }


        vector<vector<int>> ret(st.begin(),st.end());
        return ret;
    }
};