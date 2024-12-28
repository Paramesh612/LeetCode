class Solution {
private:
    // vector<string> mult(vector<string> a, vector<string> b ){
    //     vector<string> ret;
    //     for(auto &x:a){
    //         for(auto &y:b){
    //             ret.push_back(x+y);
    //         }
    //     }
    //     return ret;
    // }

    template <typename T>
    void printt(vector<T> a){
        for(auto x:a){
            cout<<x<<", ";
        }
        cout<<endl;
    }
public:
    // See first 5 mins or so of NeetCode's vid

    // Maximum that can be opened or closed = n; so 
    void createCombos( int open_avail , int close_avail, string &temp , vector<string> &ans){ //,vector<string> &ans
        if(open_avail==0 && close_avail==0) ans.push_back(temp);

        
        if(open_avail>0){ 
            temp+="(";
            createCombos( open_avail-1 , close_avail , temp , ans);
            temp.pop_back();
        }

        if(close_avail>0 && open_avail<close_avail) {
            temp+=")";
            createCombos( open_avail , close_avail-1 , temp, ans);
            temp.pop_back();
        }
        //open_avail<close_avail (OR) opened_in_string > closed_in_string, only then will we be able to close
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        createCombos(n,n,temp,ans);
        return ans;
    }
};