class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;

        int low=0, high=0,ans=0;

        for(high=0;high<s.size();high++){
            mp[s[high]]++;
            while(mp[s[high]]>2) mp[s[low++]]--;
            ans=max(ans,high-low+1);
        }

        return ans;
    }
};