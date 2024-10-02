class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        for(i=0;i<99999 ;i++){
            char ch='#';
            for(string str:strs){
                if(ch=='#' && i<str.size()) ch=str[i];
                if(i>str.size() || str[i]!=ch) return (str.substr(0,i));
            }
        }
        return "";
    }
};