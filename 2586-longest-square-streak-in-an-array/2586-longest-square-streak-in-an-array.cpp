class Solution {
public:
    // int longestSquareStreak(vector<int>& nums) {
    //     // Longest Streak they've asked. Not the shortest subsequnce lenght with longest streak
    //     // So , longest streak means. You just see the whole array
    //     int low=0, high=0;
    //     unordered_map<int,int> freq;

    //     for(int i=0;i<nums.size();i++){
    //         //Including current element in map
    //         freq[nums[i]]++;

    //         //finding Base
    //         int minKey = freq.begin().first;
    //         for(auto &x:freq){
    //             minKey = min(minKey , x.first);
    //         }
    //         //-------------

    //         long long grow = minKey;
    //         bool flag=true;
    //         for(int j=0; j<mp.size();j++){
    //             if(mp.find(grow)==mp.end()){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         if(flag){
    //             ans=max(mp.size(),ans);
    //         }else{

    //         }

    //     }
    // }

    int longestSquareStreak(vector<int>& nums){
        unordered_set<int> st(nums.begin(),nums.end());
        int maxStreak = -1;
        int m=*max_element(nums.begin(),nums.end()); //To find where to stop

        for(auto &x:nums){  
            int streak =0;
            for(long long k=x; k<=m ; k*=k){
                if(st.find(k)==st.end()) break;
                streak++;
            }

            maxStreak = max(streak , maxStreak);
        }

        return maxStreak==1?-1:maxStreak;


    }
};