class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v;
        v.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            vector<int>n(v.size()+1);
            n[0]=1;
            n[n.size()-1]=1;
            for(int j=1;j<n.size()-1;j++){
                n[j]=v[j-1]+v[j];
            }
            v=n;
        }

        return v;
    }
};