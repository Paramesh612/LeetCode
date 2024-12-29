
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
        stack<pair<int,int>> mono , mono2; // Value , index
        vector<int> nextSmall(n), prevSmall(n);

        mono.push({-1,-1});  // Helps to save writing some 'if' cases 
        mono2.push({-1,-1});  // Helps to save writing some 'if' cases 

        for(int i=n-1 ; i>=0; i--){
            while(mono.top().first >= heights[i]) mono.pop();
            nextSmall[i]=mono.top().second;
            if(nextSmall[i] == -1) nextSmall[i] = n;
            mono.push({heights[i],i});

            int j = n-1-i;
            while(mono2.top().first >= heights[j]) mono2.pop();
            prevSmall[j]=mono2.top().second;
            mono2.push({heights[j],j});
        }

        while(mono.top()!=make_pair(-1,-1)) mono.pop();  // Emptying stack

        // for(int j=0; j<n ; j++){
        // }

        cout<<"prevSmall: "; print(prevSmall);
        cout<<"nextSmall: "; print(nextSmall);

        int ans = 0;
        for(int i=0 ; i<n; i++){
            ans = max(ans , ((nextSmall[i]-1)-(prevSmall[i]+1)+1)*heights[i] );
        }

        return ans;
    }
};