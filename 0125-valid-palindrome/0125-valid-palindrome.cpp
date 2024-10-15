class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;


        while(i<j && i<s.size() && j>=0){
            while( !isalnum(s[i]) && i<j && i<s.size() && j>=0 )i++;
            while( !isalnum(s[j]) && i<j && i<s.size() && j>=0 )j--;

            if((tolower(s[i])!=tolower(s[j]))) return false;
            i++;j--;
        }
        return true;
    }
};