class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for( auto &x: t){
            mp[x]++;
        }

        for(auto &x:s){
            mp[x]--;
            if(mp[x]==0)mp.erase(x);
        }

        for(auto &x:mp){
            return x.first;
        }
        return '#';
    }
};