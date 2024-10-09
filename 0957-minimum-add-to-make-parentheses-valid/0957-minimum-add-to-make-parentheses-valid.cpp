class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return 0;
        int stack_inside=0,ans=0;
        // stack<char> st;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(') st.push('(');
        // }

        for(int ch:s){
            if(ch=='(') stack_inside++;
            else if(ch==')'){ 
                if(stack_inside>0)stack_inside--;
                else ans++;
            }
        }

        return ans+stack_inside;
    }
};