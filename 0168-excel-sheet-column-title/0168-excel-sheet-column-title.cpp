class Solution {
public:
    string convertToTitle(int num) {
        string ans;
        while(num>0){
            ans=char('A'+(num-1)%26) + ans;
            num=(num-1)/26;
        }
        return ans;
    }
};