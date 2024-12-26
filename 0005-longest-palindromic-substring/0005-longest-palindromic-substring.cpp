class Solution {
    void checkPali(string s, int low , int high, int &maxLength, int &st){
        int n=s.size();
        while(low>=0 && high<n && s[low]==s[high]){
            low--;
            high++;
        }
        printf("low = %d, high = %d\n",low,high);
        if( (high-1)-(low+1)+1 > maxLength ){
            maxLength = (high-1)-(low+1)+1;
            st = low+1;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;

        int maxLength = 1 , st = 0;
        for(int i=0; i<n; i++){
            checkPali(s,i,i,maxLength,st);
            checkPali(s,i-1,i,maxLength,st);
        }
        return s.substr(st,maxLength);
    }
};