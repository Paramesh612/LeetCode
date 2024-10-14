class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;

        for(auto &x:nums)q.push(x);

    //    while(!q.empty()){
    //         cout<<q.top()<<" ";q.pop();
    //     }return 10; 

        long long sum=0;
        for(;k>0;k--){
            sum+=q.top();
            int temp=q.top();
            q.pop();

            // cout<<"Popping: "<<temp<<"  Pushing: "<<ceil(((double)temp)/3.0)<<endl;

            q.push(ceil(((double)temp)/3.0));
        }


        return sum;
    }
};