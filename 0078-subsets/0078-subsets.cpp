class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n= nums.size();
        vector<vector<int>> ans;
        long lim = pow(2,n);
        for(int bs=0; bs<lim; bs++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(bs & (1<<i)) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};