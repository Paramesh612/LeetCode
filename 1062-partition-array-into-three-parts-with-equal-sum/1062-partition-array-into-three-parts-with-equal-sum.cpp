class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0) return false;
        int targetSum = sum/3;
        int tracker=0;
        int cnt=0;
        for(auto &x:arr){
            tracker+=x;
            if(tracker==targetSum) {tracker=0;cnt++;}
        }
        // cout<<"count: "<<cnt;
        if(cnt>=3) return true;
        return false;
    }
};