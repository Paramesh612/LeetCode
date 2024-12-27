class Solution {
public:
    int maxScoreSightseeingPair_old(vector<int>& values) {
        int n=values.size();
        vector<pair<int,int>> pre(n), post(n);
        pre[0]={values[0],0};
        post[n-1]={values[n-1]-(n-1),(n-1)};
        for(int i=1; i<n; i++){
            // pre[i]=max(pre[i-1],values[i]+i);

            if(pre[i-1].first>=values[i]+i)
                pre[i]=pre[i-1];
            else
                pre[i]={values[i]+i,i};
            
            // post[n-i-1]=max(post[n-i],values[n-i-1]-(n-i-1));
            
            if(post[n-i].first>=values[n-i-1]-(n-i-1))
                post[n-i-1] = post[n-i];
            else
                post[n-i-1] = {values[n-i-1]-(n-i-1),(n-i-1)};

        }

        cout<<"Pre: ";for(auto &x:pre)cout<<"{"<<x.first<<","<<x.second<<"} ";
        cout<<endl;
        cout<<"Post: ";for(auto &x:post)cout<<"{"<<x.first<<","<<x.second<<"} ";

        int maxVal=INT_MIN;
        for(int i=0; i<n; i++){
            int sum = pre[i].first+post[i].first;
            if( (sum>maxVal) && pre[i].second!=post[i].second ) maxVal = sum;
        }
        return maxVal;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxVal = INT_MIN;
        int currMax = values[0];
        int n = values.size();
        for(int i=0; i<n; i++){
            if(values[i]+i>=currMax){
                currMax = values[i]+i;
            }
            if(i+1<n)maxVal = max(maxVal , currMax + values[i+1]-(i+1));
        }
        return maxVal;
    }
};