class Solution {
public:
    int maxScore(string s) {
        int ones = 0 , zero=0;
        for(auto &x:s){
            if(x=='1') ones++;
            // else zero++;
        }

        int score = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') ones--;
            else zero++;

            score = max(score,ones+zero);
        }
        
        return score;
    }
};