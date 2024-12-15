class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        sort(s.begin(),s.end(),[&mp](char a , char b){
            if(mp[a]>mp[b]) return true;
            else if (mp[a]==mp[b]) return a>b;
            return false;
        });
        return s;
    }
};