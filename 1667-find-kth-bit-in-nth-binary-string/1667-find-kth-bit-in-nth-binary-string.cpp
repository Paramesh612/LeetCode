class Solution {
public:
    void invertBits(string &str){
        for(auto &it:str){
            if(it=='0') it='1';
            else it='0';
        }
    }
    char findKthBit(int n, int k) {
        string s = "0";

        // k--; // Coverting this into index

        for(int i=0; i<n && s.size()<k;i++){
            string invRev = s;
            invertBits(invRev);
            reverse(invRev.begin(),invRev.end());
            
            s=(s+"1"+invRev);
        }
        return s[k-1];
    }
};