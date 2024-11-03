class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;

        for(auto &x:nums){
            ones = (x^ones)&(~twos);
            twos = (x^twos)&(~ones);
        }
        return ones;
    }        
};