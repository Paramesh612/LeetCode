class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());

        while(st.size()>3){
            st.erase(*st.begin());
        }
        if(st.size()<3) return *st.rbegin();
        return *st.begin();
    }
};