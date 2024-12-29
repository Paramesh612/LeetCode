#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1 , n = nums.size();
        for( int i = n-2 /*(n-1), theres no element on right to swap*/; i>=0 ; i-- ){
            if(nums[i]<nums[i+1] /* Dec. Therefore, you have something bigger than i'th to swap*/){
                swapIndex = i;
                // cout << "Swap Index: "<< swapIndex;
                break; // Coz I want the smallest weighted one
            }
        }

        if(swapIndex == -1){
            /*
            Its the last perm.
            Therefore return the first perm

            But how ? Sort? Yes
            But also, reverse. Coz the last perm, means theres nothing larger
            Therefore , reverse to get the smallest
            */

            reverse(nums.begin(),nums.end());
            return;
        }

        // Intuition : if el. till now were strictly increasing (from rev) , then smallest is at LAST;
        // But it needs to be larger than nums[swapIndex], only then will the result be larger,
        // Bec, only then youll be swapping a greater number for a heavier index
        
        // cout<<endl<<"Swapping "<<swapIndex<<" and "<<n-1;
        for(int j=n-1; j>swapIndex ; j--){
            if(nums[j]>nums[swapIndex]){
                swap(nums[swapIndex],nums[j]);
                break;
            }
        }
        //Now you gotta , reorder the others, so, its the smallest value possible, after 'current'
        sort(nums.begin()+swapIndex+1,nums.end());

    }
};