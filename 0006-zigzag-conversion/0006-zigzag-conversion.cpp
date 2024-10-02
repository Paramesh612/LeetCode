class Solution {
public:
    string convert(string s, int numRows) {

        // if(numRows==1) return s;

        vector<string> str_arr(numRows);
        int i=0;
        int current=0;
        bool goingUp = false;
        while(i<s.size()){
            str_arr[current].push_back(s[i++]);
            if( !goingUp ){
                if(current+1 < numRows)current++;
                else{ 
                    if(current-1>=0)current--;
                    goingUp = true;
                }
            }
            else if( goingUp ){
                if(current-1 >= 0) current--;
                else{
                    if(current+1< numRows)current++;
                    goingUp = false;
                }
            }
        }
        string ans="";
        for(string str:str_arr){
            ans+=str;
        }
        return ans;
    }
};