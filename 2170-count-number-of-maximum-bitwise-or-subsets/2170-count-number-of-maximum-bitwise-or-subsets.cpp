class Solution {
public:
    void recurse(vector<int> nums, int i , int val ,int maxVal, int &count) {
        if (i == nums.size()) {
            if(val==maxVal)count++;
            return;
        }
        recurse(nums,i+1,val|nums[i],maxVal,count);
        recurse(nums,i+1,val,maxVal,count);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxVal = 0;
        for (auto& x : nums) {
            maxVal |= x;
        }
        // cout<<"Maximum Or Val: "<<maxVal;

        int count = 0;
        recurse(nums, 0 , 0 , maxVal , count);
        return count;
    }
};