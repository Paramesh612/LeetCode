class Solution {
public:

    int binarySearch(vector<int>& arr, int target,int low,int high){
        if(low>high){
            return -1;
        }
        int mid=(low+high)/2;
        if(arr[mid]==target)
            return mid;
        
        if(arr[low]<=arr[mid] ){            //Left part is sorted
            if( arr[low]<=target && target<arr[mid])        
                return binarySearch(arr,target,low,mid-1);
            else
                return binarySearch(arr,target,mid+1,high);
        }else{ // ie. if(arr[mid]<=arr[high])
            if( target>arr[mid] && target<=arr[high])
                return binarySearch(arr,target,mid+1,high);
            else
                return binarySearch(arr,target,low,mid-1);

        }
        return -1;
    } 

    int search(vector<int>& arr, int target) {
                return binarySearch(arr,target,0,arr.size()-1);
    }
};