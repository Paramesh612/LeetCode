class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        unordered_set<int> st(arr.begin(),arr.end());
        int maxv=INT_MIN;
        for(int el : arr){
            if(st.find(el-1)==st.end()){
                int start=el;
                while(st.find(start)!=st.end()){
                    start++;
                }
                maxv=max(maxv , start-el);
            }
        }
        return maxv;
    }
};