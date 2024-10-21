class Solution {
public:
    void solution(string s , unordered_set<string>&st , int &count , int start){
        if(start == s.size()){
            count= max((int)st.size(),count);
            return;
        } 

        for(int i = start ; i < s.size() ; i++ ){
            string temp = s.substr(start , i-start+1);
            if(st.find(temp)==st.end()){ 
                st.insert(temp);
                solution(s,st,count,i+1);
                st.erase(temp);
            }

        }
    }
    int maxUniqueSplit(string s) {
        int count=0;
        unordered_set<string>st;
        solution(s,st,count,0);
        return count;
    }
};