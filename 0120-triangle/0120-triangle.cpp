class Solution {
public:
    int findMin(vector<vector<int>>& triangle, pair<int,int>&root){
        if(root.first >= triangle.size()){ 
            return 0;
        }
        root.first++;
        int leftMin = findMin(triangle,root) ;
        root.second++;
        int rightMin = findMin(triangle,root);
        root.first--;
        root.second--;

        return triangle[root.first][root.second] + min(leftMin,rightMin);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0) triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1) triangle[i][j]+=triangle[i-1][j-1];
                else triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }

        return *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
    }
};