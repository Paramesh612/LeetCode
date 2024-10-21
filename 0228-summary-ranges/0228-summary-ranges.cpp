class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<string>ans;
        int start=arr[0];
        arr.push_back(INT_MIN);
        for(int i=0;i<arr.size()-1;i++){
            if((long)arr[i+1]!=(long)arr[i]+1){
                string temp = "";
                if(start!=arr[i]){
                temp+=(""+to_string(start)+"->"+to_string(arr[i]));
                }
                else{
                    temp+=(""+to_string(start));
                }
                ans.push_back(temp);
                start=arr[i+1];
            }
        }
        return ans;
    }
};