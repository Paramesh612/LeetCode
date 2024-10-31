class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        vector<int> ans;
        vector<pair<int,int>> dir={{0,+1},{+1,0},{0,-1},{-1,0}};

        auto current = make_pair(0,0);
        int i=0 , m=1;
        int up=0,down=matrix.size(),left=0,right=matrix[0].size();

        for(int j=0;j<(matrix.size()*matrix[0].size());j++){
            matrix[current.first][current.second] = m++;
            
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
        return matrix;      
    }
};