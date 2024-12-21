class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),[](vector<int> &a, vector<int> &b){return a[0]!=b[0]?a[0]>b[0]:a[1]<b[1];}); 
        for(auto &x : people)ans.insert(ans.begin()+x[1],x);
        return ans;
    }

};