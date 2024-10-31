class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = 0.0;
        int maxDiagArea=0;
        for(auto     &x:dimensions){
            double currentDiag = sqrt((x[0]*x[0])+(x[1]*x[1]));
            if(currentDiag > maxDiag){
                maxDiag = currentDiag;
                maxDiagArea = x[0]*x[1];
            }else if(currentDiag == maxDiag){
                maxDiagArea = max(maxDiagArea,x[0]*x[1]);
            }
        }
        return maxDiagArea;
    }
};