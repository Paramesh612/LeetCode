#include<algorithm>
class Solution {
public:
    string addStrings(string num1, string num2, int offset) {
        int m = num1.size() , n=num2.size();
        int i=m-1-offset,j=n-1;
        int carry=0;
        string ans="";

        for(int k=m-1;k>i;k--) ans+=num1[k];

        while(i>=0 && j>=0){
            int sum = charToInt(num1[i])+charToInt(num2[j])+carry;
            ans+=to_string(sum%10);
            carry= sum/10;
            i--;j--;
        }
        while(i>=0){
            int sum = charToInt(num1[i])+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
            i--;
        }
        while(j>=0){
            int sum = charToInt(num2[j])+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
            j--;
        }
        if(carry!=0) ans += to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }


    int charToInt(char x){
        return x-'0';
    }

    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int i= num1.size()-1;
        int j= num2.size()-1;
        if(j>i) return multiply(num2,num1);
        int offset=1;
        string ans="", prev="";
        int carry=0;

        // cout<<"Test: "<<addStrings("738","6",2)<<endl;
        while(j>=0){    
            ans="";
            carry=0;
            i=num1.size()-1;
            while(i>=0){ //&& j>=0
                int a = charToInt(num1[i]);
                int b = charToInt(num2[j]);

                int pdt= a*b + carry;
                ans+=to_string(pdt%10);
                carry = pdt/10;
                i--;
            }
            if(carry) ans+=to_string(carry);
            reverse(ans.begin(),ans.end()); // One line of ans;
            // cout<<"Ans:"<<ans<<endl;
            if(prev!=""){
                // for(int k=0;k<offset;k++) ans+="0";
                ans=addStrings(prev,ans,offset);
                offset++;
            }
            // cout<<"Current Ans:"<<ans<<endl;
            prev=ans;   
            j--;
        }
        return ans.empty()?"0":ans;
    }
};