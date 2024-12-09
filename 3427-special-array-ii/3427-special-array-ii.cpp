class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>prefix(nums.size());
        prefix[0]=0;

        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+( ((nums[i]&1)^(nums[i-1]&1)) ? 0:1 );
        }

        vector<bool> ans;
        for(auto &x:queries){
            if( prefix[x[0]] == prefix[x[1]] ) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};