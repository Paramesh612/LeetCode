class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return helper(nums,upper) - helper(nums,lower-1);
    }

    long long helper(vector<int>& nums, int cap){
        long long res=0;
        for(int i=0,j=nums.size()-1 ; i<j && i<nums.size();i++){
            while(i<j && nums[i]+nums[j]>cap) j--;
            res+=j-i;
        }
        return res;
    }
};