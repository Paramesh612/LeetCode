class Solution {
private:
    bool isVowel(char a){
        if(a=='a' || a=='o' || a=='e' ||a=='i' ||a=='u') return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> count , ans;

        count.push_back(0);
        for(auto &str : words){
            if(isVowel(str[0]) && isVowel(str[str.size()-1])) count.push_back(count.back()+1);
            else count.push_back(count.back());
        }

        for(auto &x:queries){
            ans.push_back(count[x[1]+1] - count[x[0]]);
        }
        return ans;
    }
};