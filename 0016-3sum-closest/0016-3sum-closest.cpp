class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        int k , diff=INT_MAX , ret = (nums[0]+nums[1]+nums[2]);
        diff=abs(target-(nums[0]+nums[1]+nums[2]));

        for(k=0;k<n-2;k++){
            i=k+1;
            j=n-1;
            // int targetTemp=target-nums[k];

            while(i<j){
                int currSum= nums[i]+nums[j] + nums[k];
                if(abs(target - currSum)<diff){
                    diff=abs(target - currSum);
                    ret=currSum;
                }

                if(currSum>target) j--;
                else if(currSum<target)i++;
                else return ret;
            }
        }
        return ret;
    }
};