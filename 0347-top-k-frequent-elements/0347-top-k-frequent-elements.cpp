class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;  //Freq , Num
        set<pair<int,int>> st; //Freq , Num
        vector<int>ans;
        unordered_map<int,int> mp;
        for(auto &x:nums)mp[x]++;

        for(auto &x:mp) pq.push({x.second,x.first});

        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;



    }
};