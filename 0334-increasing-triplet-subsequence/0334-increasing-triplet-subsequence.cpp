class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1= INT_MAX , min2=INT_MAX;
        for(auto &x:nums ){
            if(x<=min1) min1=x;
            else if(x<=min2) min2=x;
            else return true;
        }   
        return false;
    }
};