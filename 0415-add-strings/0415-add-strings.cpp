class Solution {
public:
    int stoi(char x){
        return x-'0';
    }
    string addStrings(string num1, string num2) {
        int m = num1.size() , n=num2.size();
        int i=m-1,j=n-1;
        int carry=0;
        string ans="";
        while(i>=0 && j>=0){
            int sum = stoi(num1[i])+stoi(num2[j])+carry;
            ans+=to_string(sum%10);
            carry= sum/10;
            i--;j--;
        }
        while(i>=0){
            int sum = stoi(num1[i])+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
            i--;
        }
        while(j>=0){
            int sum = stoi(num2[j])+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
            j--;
        }
        if(carry!=0) ans += to_string(carry);
        reverse(ans.begin(),ans.end());
        /*
        while(ans[i]=='0'){
            i++;
        }
        return ans.substr(i,ans.size()-i);
        */
        return ans;
    }
};