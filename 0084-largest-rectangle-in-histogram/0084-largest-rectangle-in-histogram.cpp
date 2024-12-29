
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
        int n=heights.size();
        stack<pair<int,int>> mono; // Value , index
        vector<int> nextSmall(n), prevSmall(n);

        mono.push({-1,-1});  // Helps to save writing some 'if' cases 

        for(int i=n-1 ; i>=0; i--){
            while(mono.top().first >= heights[i]) mono.pop();
            nextSmall[i]=mono.top().second;
            if(nextSmall[i] == -1) nextSmall[i] = n;
            mono.push({heights[i],i});
        }

        while(mono.top()!=make_pair(-1,-1)) mono.pop();  // Emptying stack

        for(int i=0; i<n ; i++){
            while(mono.top().first >= heights[i]) mono.pop();
            prevSmall[i]=mono.top().second;
            mono.push({heights[i],i});
        }

        cout<<"prevSmall: "; print(prevSmall);
        cout<<"nextSmall: "; print(nextSmall);

        int ans = 0;
        for(int i=0 ; i<n; i++){
            ans = max(ans , ((nextSmall[i]-1)-(prevSmall[i]+1)+1)*heights[i] );
        }

        return ans;
    }
};