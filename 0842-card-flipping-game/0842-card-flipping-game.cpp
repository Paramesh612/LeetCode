class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        /// Find the min number thats not back to back

        int minVal=INT_MAX;
        unordered_set<int> notEligible;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]==backs[i]){
                notEligible.insert(fronts[i]);
            }
        }

        for(int i=0 ; i< fronts.size();i++){
            if(fronts[i]!=backs[i] && notEligible.count(fronts[i])<=0 && fronts[i]<minVal ){
                minVal = fronts[i];
            }
            if(fronts[i]!=backs[i] && notEligible.count(backs[i])<=0 && backs[i]<minVal ){
                minVal = backs[i];
            }
        }

        if(minVal == INT_MAX) return 0;
        return minVal;
    }
};