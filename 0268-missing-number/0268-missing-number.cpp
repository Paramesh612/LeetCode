class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int expected = ((nums.size()+1)*nums.size())/2;

        return expected - sum;
    }
};