class Solution {
public:
    string compressedString(string word) {
        int count=1;
        string ans="";
        word+='#';
        for(int i=0;i<word.size()-1;i++){
            if(word[i]==word[i+1] && count<9 ) count++;
            else{
                ans+=(to_string(count)+word[i]);
                count=1;
            }
        }

        return ans;
    }
};