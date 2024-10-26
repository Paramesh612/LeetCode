class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int low, int high){
        if(low>high) return false;
        int mid=(low+high)/2;
        pair<int,int> midIndex = {(mid/matrix[0].size()), (mid%matrix[0].size())};

        if(matrix[midIndex.first][midIndex.second]==target) return true;
        else if (matrix[midIndex.first][midIndex.second]<target) return helper(matrix,target,mid+1,high);
        else return helper(matrix,target,low,mid-1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix,target,0,(matrix.size()*matrix[0].size())-1);
    }
};