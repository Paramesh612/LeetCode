class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int count0=0;

        for (auto& x : arr) {
            if(x==0) count0++;
            if (x != 0 && st.count(x * 2)) {
                // cout<<"True for: "<<x<<endl;
                return true;
            } else if (x != 0 && x % 2 == 0 && st.count(x / 2)) {
                // cout << "True for: " << x << endl;
                return true;
            }
        }
        if(count0>1) return true;
        return false;
    }
};