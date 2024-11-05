class Solution {
public:
    int minChanges(string s) {
        char start=s[0];int ans =0, i;
        for(i=0;i<s.size();i++) if(!(i%2)) start = s[i]; else if(s[i]!=start) ans++; return ans;
    }
};