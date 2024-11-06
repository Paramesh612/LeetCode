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
        // vector<pair<int,int>> minMax;
        int min1=nums[0] , max1=nums[0] , minMax_back_second=INT_MIN , minMax_back_first=INT_MAX;

        // minMax.push_back({INT_MAX,INT_MIN});

        int numBitsPrev=findBits(nums[0]);
        for(int i=1; i<nums.size() ;i++){
            int bitsNow =findBits(nums[i]);
            if(bitsNow!=numBitsPrev){
                if (minMax_back_second > min1) return false;

                minMax_back_first=min1;
                minMax_back_second=max1;
    
                min1=nums[i];
                max1=nums[i];
            }else{
                min1=min(min1,nums[i]);
                max1=max(max1,nums[i]);
            }
            numBitsPrev=bitsNow;
        }

        if (minMax_back_second > min1) return false;
        return true;
    }
};