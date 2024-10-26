class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<pair<int,int>> dir={{0,+1},{+1,0},{0,-1},{-1,0}};

        auto current = make_pair(0,0);
        int i=0;
        int up=0,down=matrix.size(),left=0,right=matrix[0].size();

        for(int j=0;j<(matrix.size()*matrix[0].size());j++){
            ans.push_back(matrix[current.first][current.second]);
            
            //Update Current
            int nextRow=current.first+dir[i].first;
            int nextCol=current.second+dir[i].second;
            if(nextRow>=up && nextRow<down && nextCol>=left && nextCol<right){
                current.first=nextRow;
                current.second=nextCol;
            }else{
                if(i==0)up++;
                else if(i==1) right--;
                else if(i==2) down--;
                else if(i==3) left++;

                i= (i+1)%4;
                current.first+=dir[i].first;
                current.second+=dir[i].second;
            }
        }
        return ans;
    }
};