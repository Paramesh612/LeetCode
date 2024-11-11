class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=nums.size()-1 ; i>=0 ;i-- ){
            if(__builtin_popcount(i)==k)sum =sum+nums[i];
        }
        return sum;
    }
};