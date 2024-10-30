class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp="";
        // s+=' ';
        int i;
        int lim=0;
        while(i<s.size() && s[lim]==' ')lim++;
        for(i=s.size()-1 ; i>=lim ; i--){
            char x=s[i];
            if(x==' '){
                while(i>=0 && s[i]==' ')i--;
                i++;
                reverse(temp.begin(),temp.end());
                ans+=temp;
                if(!ans.empty()) ans+=" ";
                temp="";
            }
            else{
                temp+=x;
            }
        }
        while(i>=0 && s[i]==' ')i--;
        i++;
        reverse(temp.begin(),temp.end());
        ans+=temp;
                
        return ans;
    }
};