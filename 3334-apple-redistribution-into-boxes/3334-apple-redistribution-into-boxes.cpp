class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // priority_queue<int> pq;
        int totalApples=accumulate(apple.begin(),apple.end(),0);
        // for(int &x:apple) totalApples+=x;
        // for(int &x:capacity) pq.push(x);

        // while(){}
        sort(capacity.begin(),capacity.end(),[](int a, int b){
            return a>b;
        });
        int i=0;
        for(i=0;i<capacity.size() && totalApples>0 ;i++){
            totalApples-=capacity[i];
        }
        return i;
    }
};