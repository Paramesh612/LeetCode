class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // y is repeated -- x is missing
        // therefore y-x = 
        int n=  grid.size()*grid.size();
        long long ActualSum= (n*(n+1))/2;
        long long sum=0;
        unordered_set<int> st;
        int y;
        for(auto &row:grid){
            for(auto &el:row){
                if(st.find(el)!=st.end()) y=el;
                st.insert(el);
                sum+=el;
            }
        }

        // ActualSum + y - x = sum
        // x= ActualSum - sum + y
        // I can find y by duplicate 
        


        return {y,(int)(ActualSum - sum + y)};
    }
};