class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        int pos=s.size()-1;
        for(int i= s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                count+=(pos-i);
                pos--;
            }
        }
        return count;
    }
};