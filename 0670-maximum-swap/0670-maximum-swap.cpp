class Solution {
public:
    vector<int> toVector(int num){
        vector<int>v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        return v;
        
    }

    int toNum(vector<int> v){
        int ret=0;
        for(auto &x:v){
            ret+=x;
            ret=ret*10;
        }
        return ret/10;
    }

    int maximumSwap___Param(int num) {
        int n=1+log10(num);
        int copy=num;
        vector<int> digs = toVector(num);
        vector<pair<int,int>> sorted; //el,index

        for(int i=0;i<digs.size();i++){
            sorted.push_back({digs[i],i});
        }
        sort(sorted.begin(),sorted.end(),[](pair<int,int> a , pair<int,int> b){
            if(a.first>b.first) return true;
            else if(a.first==b.first) return a.second>b.second;
            else return false;

        });

        for(auto &x:sorted)cout<<x.first<<","<<x.second<<endl;

        for(int i=0;i<digs.size();i++){
            if(sorted[i].first>digs[i] && sorted[i].second>i ){
                swap(digs[i],digs[sorted[i].second]);
                break;
            }
        }

        return toNum(digs);
        // bool flag=true;
        // for(int i=0;i<n-1;i++){
        //     if(arr[i]>arr[i+1]){
        //         flag=false;
        //         break;
        //     }
        // }

        // if(flag) return num
    }

    int maximumSwap(int num){
        vector<int> v = toVector(num);
        int n=v.size(); // 1+log10(num);
        for(int i=0;i<n;i++){
            int maxElIndex=i;
            for(int j=n-1;j>i;j--){
                if(v[j]>v[maxElIndex]){
                    maxElIndex=j;

                }
            }
            if(maxElIndex!=i){
                swap(v[i],v[maxElIndex]);
                break;
            }
        }
        return toNum(v);
    }
};