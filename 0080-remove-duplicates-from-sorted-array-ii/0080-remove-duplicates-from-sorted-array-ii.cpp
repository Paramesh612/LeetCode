class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos=1;
        int currentStartPosition=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                if(i-currentStartPosition < 2 ) nums[pos++]=nums[i];
            }else{
                nums[pos++]=nums[i];
                currentStartPosition = i;
            }
        }
        return pos;
    }
};