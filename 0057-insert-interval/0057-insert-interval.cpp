class Solution {
public:
    // int binSearchToFindPosition(vector<vector<int>>& intervals, vector<int>& newInterval,int low , int high){
    //     if(low>high) return -2;
    //     int mid=(low+high)/2;

    //     if(mid==0 && newInterval[0]<intervals[mid][0]) return -1;
    //     if( mid+1 <intervals.size() && newInterval[0]>=intervals[mid][0] && newInterval[0]<=intervals[mid+1][0] ){
    //         return mid;
    //     }
    //     else if(newInterval[0]>=intervals[mid][0]){
    //         return binSearchToFindPosition(intervals,newInterval,mid+1,high);
    //     }else{
    //         return binSearchToFindPosition(intervals,newInterval,low,mid-1);
    //     }
    //     return -1;
    // }
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     if(intervals.empty()) return {{newInterval[0],newInterval[1]}};
    //     intervals.push_back({99991,99999});
    //     int index = binSearchToFindPosition(intervals,newInterval,0,intervals.size()-1);

    //     // if(index==-1) return intervals;

    //     int flag1=true,flag2=true;
    //     if(intervals[index][1]>=newInterval[0]){
    //         flag1=false;
    //     }
    //     if(newInterval[1] >= intervals[index+1][0]){
    //         flag2=false;
    //     }

    //     int start=newInterval[0];
    //     int end = newInterval[1];
    //     int count=0;
    //     if(!flag1){ 
    //         start=min(intervals[index][0],newInterval[0]); 
    //         end=max(intervals[index][1],newInterval[1]); 
    //         count++;
    //     }
    //     for(int i=index+1; i< intervals.size(); i++){
    //         if(newInterval[1]>=intervals[i][0]){
    //             end=max(end,intervals[i][1]);
    //             count++;
    //         }else break;
    //     }
        
    //     cout<<"Index: "<<index<<endl<<"count: "<<count;
    //     intervals.erase(intervals.begin()+index,intervals.begin()+index+count);
    //     intervals.insert(intervals.begin()+index,{start,end});

    //     // vector<vector<int>> result;
    //     // for (int i = 0; i <= index; i++) {
    //     //     result.push_back(intervals[i]);
    //     // }
    //     // result.push_back({start, end});
    //     // for (int i = index + 1; i < intervals.size(); i++) {
    //     //     result.push_back(intervals[i]);
    //     // }


    //     result.pop_back();
    //     return result;
    // }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart=newInterval[0];
        int newEnd= newInterval[1];

        vector<vector<int>>ans;
        int i=0;
        int n = intervals.size();
        while(i<n && newStart>intervals[i][0]){
            ans.push_back(intervals[i]);
            i++;
        }

        if(ans.empty() || ans.back()[1]<newStart){
            ans.push_back(newInterval);
        }else{
            // ans.push_back({min(ans.back()[0])});
            ans.back()[1]= max(ans.back()[1],newEnd);
        }

        while(i<n){
            int start= intervals[i][0];
            int end= intervals[i][1];

            if(ans.back()[1]<start){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(end, ans.back()[1]);
            }
            i++;
        }
        return ans;
    }
};