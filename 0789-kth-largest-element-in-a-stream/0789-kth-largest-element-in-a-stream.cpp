class KthLargest {
public:
    int k;

    vector<int>nums;
    priority_queue<int,vector<int>,greater<int>> pq;

    multiset<int> st;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;

        for(auto &x:nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();  //pop the smallest element
        }
    }   
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */