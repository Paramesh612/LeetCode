
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
        vector<int> prevSmall(n); // nextSmall(n),

        pair<int,int> stopper = {-1,-1};
        mono.push(stopper);  // Helps to save writing some 'if' cases 

        for(int j=0 ; j<n; j++){
            //Finding PrevSmallest
            while(mono.top().first >= heights[j]){ 
                // nextSmall[mono.top().second] = j;
                ans = max( ans, ((j-1)-(prevSmall[mono.top().second]+1)+1)*heights[mono.top().second] );
                mono.pop();
            }
            prevSmall[j]=mono.top().second;
            mono.push({heights[j],j});

        }
        
        while(mono.top() != stopper){ 
            ans = max( ans, ((n-1)-(prevSmall[mono.top().second]+1)+1)*heights[mono.top().second] );
            mono.pop();
        }
        // for(int i=0 ; i<n; i++) ans = max(ans , ((nextSmall[i]-1)-(prevSmall[i]+1)+1)*heights[i] );
        return ans;
    }
};