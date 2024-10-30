class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1=-1,min2=-1;

        int n = nums.size();
        for(int i=1;i<n;i++){
            if( min1 == -1 || nums[i]<=nums[min1]){
                min2=min1;
                min1=i;
            }else if( min2==-1 || (nums[i]>nums[min1] && nums[i]<nums[min2])){
                min2=i;
            }
        }
        cout<<"nums[0]: "<<nums[0]<<endl;
        cout<<"nums[min1]: "<<nums[min1]<<endl;
        cout<<"nums[min2]: "<<nums[min2]<<endl;
        
        return nums[0]+nums[min1]+nums[min2];
    }
};