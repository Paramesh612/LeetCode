class KthLargest {
public:
    int k;
    vector<int>nums;
    // priority_queue<int> pq;

    multiset<int> st;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;

        st.insert(nums.begin(),nums.end());
    }
    
    int add(int val) {

        // for(auto &x:st)cout<<x;
        // cout<<endl;

        st.insert(val);
        auto ret=st.end();
        for(int i=0;i<k;i++) ret--;
        return *(ret);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */