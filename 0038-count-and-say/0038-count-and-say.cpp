class Solution {
public:
    string countAndSay(int n) {
        string str="1";
        int count=0;
        
        for(int i=1;i<n;i++){
            
            
            
            
            string temp="";
            count=1;
            str+="#";
            // d<<"String: "<<str<<endl;
            for(int j=0;j<str.size()-1;j++){
                if(str[j]==str[j+1]){
                    count++;
                }else{
                    // d<<"count of "<<str[j]<<" is "<<count<<endl;
                    temp= temp + ( to_string(count) + (str[j]) );
                    // d<<"temp: "<<temp<<endl;
                    count=1;
                }
            }
            // d<<temp<<endl;
            str=temp;








            
        }
        return str;
    }
};