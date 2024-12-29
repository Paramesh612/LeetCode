class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> mono;
        vector<int> ans(nums.size(),-1);

        for(int j = 2*(nums.size()-1); j>=0 ; j--){
            int i = j % nums.size();
            while(!mono.empty() && mono.top()<=nums[i]) mono.pop();
            if(!mono.empty()) ans[i] = mono.top();
            mono.push(nums[i]);
        } 
        return ans;
    }
};