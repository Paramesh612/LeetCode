
class Solution {
private:
    template <typename T>
    void print(vector<T> v){
        for(auto &x:v) cout<<x<<"  ";
        cout<<endl;
    }
public:
    // Saw the hint of taking NextSmall and PrevSmall. Others I cracked :)
    int largestRectangleArea(vector<int>& heights) {
        //STOP STALKING ME BLUD
        
        int n=heights.size(), ans = 0;
        stack<pair<int,int>> mono; // Value , index
        // vector<int> prevSmall(n); // nextSmall(n),

        pair<int,int> stopper = {-1,-1};
        mono.push(stopper);  // Helps to save writing some 'if' cases 

        for(int j=0 ; j<n; j++){
            //Finding PrevSmallest
            while(mono.top().first >= heights[j]){ 
                /*
                ans = max( ans, ((j-1)-(prevSmall[mono.top().second]+1)+1)*heights[mono.top().second] );
                Simplifying the formula:  */

                // What is the prevSmall value. Isnt it actually the element below????
                // Then why store it

                int indexOfOldTop = mono.top().second;
                mono.pop();

                // The new top is the nextSmall of that old top
                ans = max( ans, (j-mono.top().second-1)*heights[indexOfOldTop]);


            }
            mono.push({heights[j],j});

        }
        
        while(mono.top() != stopper){ 
            int indexOfOldTop = mono.top().second;
            mono.pop();
            ans = max( ans, (n-mono.top().second-1)*heights[indexOfOldTop]);
        }
        return ans;
    }
};