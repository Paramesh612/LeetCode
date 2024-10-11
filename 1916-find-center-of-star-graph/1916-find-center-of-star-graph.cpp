class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(auto &x:edges){
            if(st.find(x[0])!=st.end()) return x[0];
            if(st.find(x[1])!=st.end()) return x[1];

            st.insert(x[0]);
            st.insert(x[1]);
        }
        return -1;
    }
};