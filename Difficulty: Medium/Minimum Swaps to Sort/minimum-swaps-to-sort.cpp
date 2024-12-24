//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        vector<pair<int,int>> newArr;
        for(int i=0; i<arr.size(); i++){
            newArr.push_back({arr[i],i});
        }
        
        sort(newArr.begin(),newArr.end());
        
        int curr=0,count=0;
        while(curr<arr.size()){
            if(curr!=newArr[curr].second){
                swap(newArr[curr],newArr[newArr[curr].second]);
                count++;
            }
            else 
                curr++;
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends