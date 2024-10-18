class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,string> mp;
        // int i=0,j=0;
        vector<string> v;
        string temp=""; s+=" ";
        for(auto &ch:s){
            if(ch==' '){
                temp+="#";
                v.push_back(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        // v.push_back(temp);

        for(auto &x:v) cout<<x<<",";

        if(v.size()!=pattern.size()) return false;

        for(int i=0;i<pattern.size();i++){
            string tempS="";
            tempS+=pattern[i];


            if(mp.find(tempS)==mp.end()){
                if(mp.find(v[i])!=mp.end()) return false;
                mp[tempS]=v[i];
                mp[v[i]]=tempS;
            }
            else if(mp.find(tempS)!=mp.end()){
                if(mp.find(v[i])==mp.end()) return false;
                if(mp[tempS]!=v[i] || mp[v[i]]!=tempS) return false;
            }
        }


        // while( i<pattern.size() && j<v.size() ){
        //     string tempS="";
        //     tempS+=pattern[i];
        //     if(mp.find(tempS+"")==mp.end()){
        //         mp[tempS]=v[j];
        //         mp[v[j]]=tempS;
        //         i++;j++;
        //     }
        //     else if(mp.find(tempS)!=mp.end() && tempS!=mp[v[j]] ) return false;
        //     else if(mp.find(tempS)!=mp.end()  && mp[tempS]!=v[j] ) i++;


        //     // while(mp.find(tempS!=mp.end()) && i<pattern.size()) i++;
            
        //     // if(i>=pattern.size() && j<=v.size()) return false;
        //     //  mp[tempS]=v[j];
        // }

        for(auto &x:mp) cout<<x.first<<"-->"<<x.second<<endl;

        return true;
    }
};  