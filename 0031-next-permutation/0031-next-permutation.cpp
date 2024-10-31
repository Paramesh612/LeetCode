#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        string str(nums.begin(),nums.end());
        next_permutation(nums.begin(),nums.end());
    }
};