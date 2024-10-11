class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<int,vector<int>,greater<int>> freeChairs;

        for(int i=0; i<n; i++){
            freeChairs.push(i);
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> occupiedChairs;
        /* ( DepTime , index )
         if (DepTime <= CurrentTime) free(Element)
         free(Element)->{
            remove from occupiedChairs
            add indexNumber to freeChairs
         } 
        */

        for(int i=0;i<n;i++){
            int arrival =times[i][0];
            int depature = times[i][1];
            int friendNumber = times[i][2];


            while(!occupiedChairs.empty() && occupiedChairs.top().first<=arrival){
                freeChairs.push(occupiedChairs.top().second);
                //pop them
                occupiedChairs.pop();
            }

            if(friendNumber==targetFriend){
                return freeChairs.top();
            }
            
            occupiedChairs.push({depature , freeChairs.top()});
            freeChairs.pop();
        }
        return 0;
    }
};