class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // vector<pair<int,int>> st;  //val , index
        stack<int> st;
        int maxWidth=0;
        // int low=0,high=0;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]>nums[i]){
                st.push(i);
            }
        }

        for(int j=nums.size()-1;  j>=0; j--){
            while(!st.empty() && nums[st.top()]<=nums[j]){
                maxWidth = max(maxWidth , j-st.top());
                st.pop();
            }
        }
        return maxWidth;
    }
};