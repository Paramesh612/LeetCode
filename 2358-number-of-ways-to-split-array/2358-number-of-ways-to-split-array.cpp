class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rsum =0 , lsum = 0 , validCount = 0;

        for(auto &x:nums) rsum += x;
        for(int i=0;i<nums.size()-1;i++){
            lsum+=nums[i];
            rsum-=nums[i];

            if(lsum >= rsum) validCount++;
        }
        return validCount;
    }
};