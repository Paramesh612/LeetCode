class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        vector<int> ans;

        int low=0;
        int high=0;
        int notConsecAt=-1;

        for(high=1;high<k;high++){
            if(arr[high]!=arr[high-1]+1){
                notConsecAt = high-1;
            }
        }
        if(notConsecAt >= low && notConsecAt <= high){
            ans.push_back(-1);
        }else{
            ans.push_back(arr[high-1]);
        }

        // cout<<high;

        for(;high<arr.size();high++){
            if(arr[high]!=arr[high-1]+1){
                notConsecAt = high-1;
            }
            
            if(notConsecAt >= high-k+1 && notConsecAt <= high){
                ans.push_back(-1);
            }else{
                ans.push_back(arr[high]);
            }

        }

        return ans;
    }
};