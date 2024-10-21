class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int>s;

        int newN=0;

        while(true){
            if(n==1) return true;
            if(s.find(n)!=s.end()){
                return false;
            }

            s.insert(n);
            newN=0;
            while(n>0){
                newN += pow(n%10,2);
                n/=10;
            }
            n=newN;
        }
        return false;
    //     if(n==0) return false;
    //     if((int)log10(n)+1 == 1){
    //         if(n==1) return true;
    //         return false;
    //     }
    //     int newN=0;
    //     while(n>0){
    //         newN += pow(n%10,2);
    //         n/=10;
    //     }
    //     return isHappy(newN);
    }
};