class Solution {
public:
    void helper(string  s , int &ans){
        if(s.size()==1) return;
    }
    
    int minChanges(string s) {
        int start=-1 ,ans =0 ;
        for(int i=0;i<s.size();i++){
            if(i%2==0) start = s[i];
            else{
                if(s[i]!=start) ans++;
            }
        }
        return ans;
    }
};