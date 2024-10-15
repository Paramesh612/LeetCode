class Solution {
public:
    vector<string> mulVectors(string digits , unordered_map<char, string> mp, int i){
        vector<string> v;
        if(digits.size()-1==i){
            for (auto& x : mp[digits[i]]) {
                string temp = "";
                temp+=x;
                v.push_back(temp);
            }
            return v;
        }
        else{
            vector<string> v2= mulVectors(digits,mp,i+1);
            vector<string>ans;
            for(auto &x:mp[digits[i]]){
                for(auto &str:v2){
                    string temp="";
                    temp+=(x+str);
                    ans.push_back(temp);
                }
            }
            return ans;
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0)
            return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        return (mulVectors(digits,mp,0));
}
};