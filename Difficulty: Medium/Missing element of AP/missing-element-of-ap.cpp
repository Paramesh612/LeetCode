//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        if(arr.size()==2){
            return arr[0]+((arr[1]-arr[0])/2);
        }
        int n=arr.size();
        int diff = min(arr[1]-arr[0] , arr[n-1]-arr[n-2]);
        
        return BinarySearch(arr,diff,0,n-1);
        
    }
    
    int BinarySearch(vector<int> &arr, int diff, int low, int high ){
        if(low>high) return -2;
        
        int mid = (high + low) /2 ;
        
        if(arr[mid] ==  diff*mid + arr[0]){
            if(mid<arr.size() && arr[mid+1]-arr[mid] != diff) return arr[mid]+diff;
            else return BinarySearch(arr, diff, mid+1, high);
        }else{
            if(mid>0 && arr[mid]-arr[mid-1] != diff) return arr[mid]-diff;
            else return  BinarySearch(arr, diff, low, mid-1);
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends