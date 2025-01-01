//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // Print vector
    template <typename T>
    void println(vector<T> arr){
        for(auto &x:arr) cout<<x<<" ";
        cout<<endl;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        int numPairs = n-1;
        vector<vector<int>> dp(numPairs,vector<int>(numPairs,0));
        
        for(int len=0; len<numPairs; len++){
            for(int i=0; i<numPairs-len; i++){
                int j = i + len ;
                if(i==j) dp[i][j] = 0;
                else{
                    int ans = INT_MAX;
                    for(int k=i; k<j ; k++){
                        // cout<<"B4 Seg Fault";
                        ans = min(
                            ans,
                            dp[i][k]+dp[k+1][j] + (arr[i]*arr[k+1]*arr[j+1])
                        );
                        // cout<<"After Seg Fault";
                    }
                    dp[i][j] = ans;
                    dp[j][i] = ans;
                }
            }
        }
        
        // for(auto &x:dp) println(x);        
        
        // return 5;
    
        return dp[0][numPairs-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends