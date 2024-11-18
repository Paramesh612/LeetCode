class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0),pre(code.size());
        if(!k) return ans;
        else if(k<0){ 
            reverse(code.begin(),code.end());
            ans=decrypt(code,-k);
            reverse(ans.begin(),ans.end());
            return ans;
        }
        int n= code.size();

        pre[0]=code[0];
        for(int i=1; i<n; i++){
            pre[i]=pre[i-1]+code[i];
            // cout<<pre[i]<<"  ";
        }

        for(int i=0 ; i<n; i++){
            int getIndex = i+k;
            if(getIndex>=n){
                ans[i]+=pre[n-1];
                getIndex%=n;
            }
            ans[i]+=pre[getIndex];
            ans[i]-=pre[i];
        }
        return ans;
    }
};