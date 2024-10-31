class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0 , high=0;
        int sum=0;
        int ans = INT_MAX;
        for(;high<nums.size();high++){
            sum+=nums[high];
            while(low<=high && sum>=target){
                ans=min(ans,high-low+1);
                sum-=nums[low++];
            }
        }    

        return ans==INT_MAX?0:ans;
    }
};