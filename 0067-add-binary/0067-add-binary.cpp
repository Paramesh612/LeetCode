class Solution {
public:
    string addBinary(string a, string b) {
        string ans(max(a.size(),b.size())+1,'0');
        char carry='0';
        int i=a.size()-1,j=b.size()-1;
        int pos= max(i,j)+1;
        while(i>=0 && j>=0){
            int res = ((a[i]-'0')+(b[j]-'0')+(carry-'0'));
            if( res == 0 ){ ans[pos--]='0'; carry='0'; }
            else if( res == 1 ){ ans[pos--]='1'; carry='0'; }
            else if( res == 2 ){ ans[pos--]='0'; carry='1'; }
            else if( res == 3 ){ ans[pos--]='1'; carry='1'; }

            i--;j--;
        }
        while(i>=0){
            int res = ((a[i]-'0')+(carry-'0'));
            if( res == 0 ){ ans[pos--]='0'; carry='0'; }
            else if( res == 1 ){ ans[pos--]='1'; carry='0'; }
            else if( res == 2 ){ ans[pos--]='0'; carry='1'; }
            else if( res == 3 ){ ans[pos--]='1'; carry='1'; }
            i--;
        }
        while(j>=0){
            int res = ((b[j]-'0')+(carry-'0'));
            if( res == 0 ){ ans[pos--]='0'; carry='0'; }
            else if( res == 1 ){ ans[pos--]='1'; carry='0'; }
            else if( res == 2 ){ ans[pos--]='0'; carry='1'; }
            else if( res == 3 ){ ans[pos--]='1'; carry='1'; }
            j--;
        }
        ans[pos]=carry;
        return ans[0]=='0'? ans.substr(1,ans.size()-1):ans;
    }
};