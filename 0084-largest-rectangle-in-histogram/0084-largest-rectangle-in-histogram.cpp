class Solution {
public:
    // SEE submission at 2:21 ish for explanation with comments 
    // Saw the hint of taking NextSmall and PrevSmall. Others I cracked :)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans = 0;
        stack<int> mono; 
        mono.push(-1);  
        for(int j=0 ; j<=n; j++){
            while(mono.top()!=-1 && (j==n || heights[mono.top()] >= heights[j])){ 
                int indexOfOldTop = mono.top();
                mono.pop();
                ans = max( ans, (j-mono.top()-1)*heights[indexOfOldTop]);
            }
            mono.push(j);
        }
        return ans;
    }
};