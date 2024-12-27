class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &x:s){
            if(x=='{' || x=='[' || x=='(') st.push(x);
            else{
                int diffVal = (x==')')?1:2;
                if(!st.empty() && st.top()+diffVal == x) st.pop(); else return false;
            }
        }
        return st.empty()?true:false;
    }
};