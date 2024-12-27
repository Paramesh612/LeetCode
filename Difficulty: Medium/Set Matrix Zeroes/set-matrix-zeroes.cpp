//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        bool rowZero = false;
        bool colZero = false;
        
        for(auto &x:mat[0])
            if(x==0){
                rowZero = true;
                break;
            }
            
        for(int j=0;j<mat.size();j++ ){
            if(!mat[j][0]){
                colZero = true;
                break;
            }
        }
        
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(!mat[i][j]){ 
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        
        
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(!mat[i][0] || !mat[0][j]){ 
                    mat[i][j]=0;
                }
            }
        }
        
        if(rowZero){            for(auto &x:mat[0]) x=0;    
        }
        
        if(colZero) for(int j=0;j<mat.size();j++ ) mat[j][0]=0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends