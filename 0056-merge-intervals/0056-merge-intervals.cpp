class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&arr) {
        vector<vector<int>> ans;

        sort(arr.begin(),arr.end());

        int start=arr[0][0];
        int end=arr[0][1];

        arr.push_back({INT_MAX,INT_MAX});

        for(int i=0;i<arr.size();i++){
            int currentElementStart=arr[i][0];
            int currentElementEnd=arr[i][1];
            if(end>=currentElementStart){
                end=max(end,currentElementEnd);
            }else{
                ans.push_back({start,end});
                start=currentElementStart;
                end=currentElementEnd;
            }
        }   
        return ans;

    }
};