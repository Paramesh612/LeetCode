class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> repeated;
        unordered_map<int,int> mp;

        int ptr=0;
        long long sum=0 , maxSum = INT_MIN;
        for(;ptr<k;ptr++){
            sum+=nums[ptr];
            mp[nums[ptr]]++;
            if(mp[nums[ptr]]>1)repeated.insert(nums[ptr]);
        }

        if(repeated.empty())  maxSum = sum;

        for(;ptr<nums.size();ptr++){
            int currNum = nums[ptr];
            sum+= currNum ;
            
            mp[currNum]++;
            if(mp[currNum] > 1){
                repeated.insert(currNum);
            }

            int currNum2 = nums[ptr-k]; 
            sum-= currNum2;
            mp[currNum2]--;

            if(mp[currNum2]<1) mp.erase(currNum2);
            else if(mp[currNum2]==1) repeated.erase(currNum2);

            if(repeated.empty()) maxSum = max( maxSum , sum );
            
        }
        for(auto &x:repeated) cout<<x<<" ";
        if(repeated.empty()) maxSum = max( maxSum , sum );

        if(maxSum==INT_MIN) return 0;
        return maxSum;
    }
};