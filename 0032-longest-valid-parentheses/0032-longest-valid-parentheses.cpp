class Solution {
private:
    int findLongestSequence(vector<int> &arr){
        int ret = 0, cnt=0;
        for(auto &x:arr){
            if(x) cnt++;
            else cnt = 0;

            ret = max(ret,cnt);
        }
        return ret;
    }

public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> arr(s.size());
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()){
                    arr[st.top()] =1;
                    st.pop();
                    arr[i]=1;
                }
            }
        }

        int ans = findLongestSequence(arr);
        return ans;
    }
};