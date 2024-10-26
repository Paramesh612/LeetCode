class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs_og) {
        unordered_map<string,int> mp;
        vector<vector<string>> ans;

        vector<string> strs=strs_og;
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }

        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            if(mp.find(str)!=mp.end()){
                ans[mp[str]].push_back(strs_og[i]);
            }else{
                mp[str]=ans.size();

                ans.push_back({strs_og[i]});
            }
        }
        return ans;
    }
};