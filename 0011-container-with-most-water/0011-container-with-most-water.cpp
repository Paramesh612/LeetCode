class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int i=0,j=n-1,ans=0;
        while(i<=j){
            ans=max(ans,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};