class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n%3!=0) return false;
        if(n<3) return false;
         
        return isPowerOfThree(n/3);
    }
};