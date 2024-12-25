class Solution {
public:
    // bool judgeSquareSum(int c) {
    //     int tempC = (int)sqrt(c);
    //     if(tempC*tempC == c) return true;
    //     int rem = c - tempC*tempC;
    //     int temp = (int)sqrt(rem);
    //     temp *= temp;
    //     if( temp == rem ) return true;
    //     return false;
    // }

    bool judgeSquareSum(int c) {
        long long val, low = 0 , high = sqrt(c);
        while(low <= high){
            val = low*low + high*high;
            if(val  == c) return true;
            else if(val > c) high--;
            else low++;
        }
        return false;
    }
};