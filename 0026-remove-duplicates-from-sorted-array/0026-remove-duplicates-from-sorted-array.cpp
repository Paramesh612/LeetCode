class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int current=1;
        for(int i=1;i<n;i++){
            if(arr[current-1]!=arr[i]){
                arr[current++]=arr[i];
            }
        }
        return current;
    }
};