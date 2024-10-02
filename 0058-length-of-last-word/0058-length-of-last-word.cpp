class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;


        while(s[i]==' ')i--;
        int cnt=0;
        while(i>=0 && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) ){cnt++;i--;}
        return cnt;
    }
};