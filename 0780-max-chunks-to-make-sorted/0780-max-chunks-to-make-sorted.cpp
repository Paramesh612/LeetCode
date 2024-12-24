class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxx = -1, group = 0;
        for(int i=0;i<arr.size();i++){
            maxx = max(maxx,arr[i]);
            if(maxx == i){
                group++;
                maxx=-1;
            }
        }    
        return group;
    }
};