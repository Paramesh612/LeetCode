class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = INT_MIN , secondMax = INT_MIN;

        for(int i = 0;i<nums.size(); i++){
            if(nums[i]>=maxx){
                secondMax = maxx;
                maxx = nums[i];
            }else if(nums[i]>=secondMax){
                secondMax = nums[i];
            }
        }
        return (maxx-1)*(secondMax-1);
    }
};