class Solution {
public:
    int findBits(int  num){
        int c=0;
        // int nums=num;
        while(num>0){
            c+=(num&1);
            num=num>>1;
        }
        // cout<<"**No. of bits in "<<nums<<" is "<<c<<endl;
        return c;
    }
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>> minMax;
        int min1=nums[0] , min2=nums[0] , max1=nums[0] , max2=nums[0];

        minMax.push_back({INT_MAX,INT_MIN});

        for(int i=1; i<nums.size() ;i++){
            if(findBits(nums[i])!=findBits(nums[i-1])){
                if (minMax.back().second > min1) return false;

                minMax.push_back({min1,max1});
                // cout<<"Pushing... "<<min1<<","<<max1<<endl;
    
                min1=nums[i];
                max1=nums[i];
            }else{
                min1=min(min1,nums[i]);
                max1=max(max1,nums[i]);
            }
        }

        if (minMax.back().second > min1) return false;
        return true;
    }
};