class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(auto &x:arr)mp[x]++;

        for(auto &x:mp){
            if(st.find(x.second)!=st.end()) return false;
            st.insert(x.second);
        }
        return true;
    }
};