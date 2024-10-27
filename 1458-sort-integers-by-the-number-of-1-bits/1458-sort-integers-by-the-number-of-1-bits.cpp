class Solution {
public:
    int countBits(int a){
        int count=0;
        while(a>0){
            count+=(a&1);
            a>>=1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int>mp;
        sort(arr.begin(),arr.end(),[this,&mp](int a , int b){
            if(mp.find(a)==mp.end()){
                mp[a]=countBits(a);
            cout<<"Bits in "<<a<<" is "<<mp[a]<<endl;
            } 
            if(mp.find(b)==mp.end()){
                mp[b]=countBits(b);
            cout<<"Bits in "<<b<<" is "<<mp[b]<<endl;
            } 


            if(mp[a]<mp[b]) return true;
            if(mp[a]==mp[b]) return a<b;
            return  false;
        });    
        return arr;
    }
};