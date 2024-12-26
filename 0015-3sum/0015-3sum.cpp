class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int i=0,j=0,k=0;
        int n = arr.size();

        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(;i<n;i++){
            while(i>0 && i<n && arr[i-1]==arr[i]) i++;

            j=i+1;
            k=n-1;
            while(j<n && k<n && j<k){
                long long sum = arr[i]+arr[j]+arr[k];
                // printf("sum=%d, i=%d, j=%d, k= %d\n",sum,i,j,k);
                if(sum>0){ 
                    k--;
                    while(k>=0 && k+1<n && arr[k]==arr[k+1]) k--;
                }else{
                    if(!sum) ans.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    while(j<n && arr[j-1]==arr[j]) j++;   
                }
            }
        }
        return ans;
    }
};