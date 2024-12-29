
class Solution {
    //STOP STALKING ME BLUD
private:
    template <typename T>
    void print(vector<T> v){
        for(auto &x:v) cout<<x<<"  ";
        cout<<endl;
    }
public:
    // Saw the hint of taking NextSmall and PrevSmall. Others I cracked :)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans = 0;
        stack<pair<int,int>> mono , mono2; // Value , index
        vector<int> nextSmall(n), prevSmall(n);

        mono.push({-1,-1});  // Helps to save writing some 'if' cases 
        mono2.push({-1,-1});  // Helps to save writing some 'if' cases 

        for(int i=n-1 ; i>=0; i--){
            // Finding NextSmallest
            while(mono.top().first >= heights[i]) mono.pop();
            nextSmall[i]=mono.top().second;
            if(nextSmall[i] == -1) nextSmall[i] = n;
            mono.push({heights[i],i});

            //Finding PrevSmallest
            int j = n-1-i;
            while(mono2.top().first >= heights[j]) mono2.pop();
            prevSmall[j]=mono2.top().second;
            mono2.push({heights[j],j});
        }
        for(int i=0 ; i<n; i++) ans = max(ans , ((nextSmall[i]-1)-(prevSmall[i]+1)+1)*heights[i] );
        return ans;
    }
};