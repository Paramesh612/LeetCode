class NumArray {
public:
    vector<int>nums;
    vector<int>prefixSum;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(!left) return prefixSum[right];
        return prefixSum[right]-prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */