class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int counta, countb, countc;
        counta = countb = countc = 0;
        int count[3];
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        while (a > 0 || b > 0 || c > 0) {
            vector<pair<int, char>> temp;
            while (!pq.empty() &&
                   !(pq.top().first > 0 && count[pq.top().second - 'a'] < 2)) {
                auto& toPushIn = pq.top();
                temp.push_back(toPushIn);
                pq.pop();
            }
            if (pq.empty())
                break;
            pair<int, char> current = pq.top();
            pq.pop();
            ans += current.second;
            current.first--;
            count[current.second - 'a']++;
            for (int i = 0; i < 3; i++) {
                if (i != (current.second - 'a'))
                    count[i] = 0;
            }
            if (current.first > 0)
                pq.push(current);
            for (auto& x : temp) {
                pq.push(x);
            }
        }
        return ans;
    }
};