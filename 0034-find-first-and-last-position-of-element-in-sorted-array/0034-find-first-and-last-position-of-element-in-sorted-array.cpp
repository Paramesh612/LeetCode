class Solution {
public:
    void binSearch(vector<int>& nums, int &target , int low , int high, int &minIndex , int &maxIndex){
        if(low>high) return;
        int mid= (low+high)/2;

        if(target>nums[mid]) binSearch(nums,target , mid+1, high, minIndex , maxIndex);
        else if(target<nums[mid]) binSearch(nums,target , low, mid-1, minIndex , maxIndex);
        else{
            minIndex= min(minIndex,mid);
            maxIndex= max(maxIndex,mid);
            binSearch(nums,target , mid+1, high, minIndex , maxIndex);
            binSearch(nums,target , low, mid-1, minIndex , maxIndex);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int minn=INT_MAX,maxx=INT_MIN;

        binSearch(nums,target,0,nums.size()-1,minn,maxx);
        
        if(minn==INT_MAX || maxx==INT_MIN) return {-1,-1};
        return {minn,maxx};
    }
};