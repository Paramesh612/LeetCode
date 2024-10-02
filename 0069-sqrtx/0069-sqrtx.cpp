class Solution {
public:
    int mySqrt(int x) {
        unsigned long long low=0,high=x,mid;
        while(low<=high){
            mid = (low+high)/2;
            if(x>mid*mid) low=mid+1;
            else if(x<mid*mid) high=mid-1;
            else if(x==(mid*mid)) return mid; 
        }
        return high;

    }
};