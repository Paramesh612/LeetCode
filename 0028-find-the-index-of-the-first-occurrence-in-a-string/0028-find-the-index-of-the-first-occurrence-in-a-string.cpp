class Solution {
public:
    vector<int> buildLPS(string str){
        vector<int> lps(str.size());
        int i=1,j=0;
        lps[0]=0;

        for(i=1;i<str.size();i++){
            if(str[i]==str[j]) {lps[i]=j+1;j++;}
            else{
                while(str[i]!=str[j] && j>0) j=lps[j-1];
                if(str[i]==str[j]) {lps[i]=j+1;j++;}
                else lps[i]=0;
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        vector<int> lps=buildLPS(needle);
        int start=-1,j=0;
        for(int i=0;i<haystack.size() && j<lps.size();i++){
            if(haystack[i]==needle[j]){
                cout<<needle[j];
                if(j==0)start=i;    
                j++;
            }
            else{
                // cout<<endl;
                while(haystack[i]!=needle[j] && j>0) j=lps[j-1];
                start=i-j;
                if(haystack[i]==needle[j])j++;

                // i--; 
            }
        }

        cout<<endl;
        for(int i=0;i<lps.size();i++)cout<<lps[i];
        cout<<endl<<"J= "<<j;
        if(j==lps.size()) return start;
        return -1;

    }
};