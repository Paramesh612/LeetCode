class Solution {
public:
    int reverse(int x) {
        bool isNegative = x<0?true:false;
        x=abs(x);
        long long MAX = (long long)INT_MAX;
        long long ans=0;
        while(x>0){
            ans=ans+(x%10);
            ans*=10;
            x/=10;
        }
        ans/=10;
        if(ans>MAX) return 0;
        return isNegative?(-1*ans):ans;
    }
};