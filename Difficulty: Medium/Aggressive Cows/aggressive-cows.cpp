//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    
  private:
    bool isAns(vector<int> &stalls , int k , int candidate){
        int lastKept = stalls[0];
        k--;
        
        for(int i=1; i<stalls.size();i++){
            if(stalls[i] - lastKept >= candidate){
                lastKept = stalls[i];
                k--;
            }
            if(k<=0) return true;
        }
        if(k>0) return false;
    }
    
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int maxVal = stalls[n-1] - stalls[0];
        
        int left = 1;
        int right = maxVal;
        int mid;
        
        while(left <= right){
            // cout<<"Hii"<<endl;
            mid = (left + right) /2;    
            // cout<<"isAns of "<<mid<<" is: "<<isAns(stalls,k,mid)<<endl;
            if(isAns(stalls,k,mid)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends