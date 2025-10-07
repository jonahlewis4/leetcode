class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, queue<int>> next;
        for(int i = 0; i < rains.size(); i++) {
            int rain = rains[i];
            next[rain].push(i);
        }

        for(auto & [_, q] : next) {
            q.pop();
        }

        unordered_set<int> wet;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < rains.size(); i++) {
            int lake = rains[i];
            if(lake == 0) {
                if(pq.empty()) {
                    rains[i] = 123456789;
                    continue;
                }
                int saved = pq.top();
                pq.pop();
                int savedLake = rains[saved];
                wet.erase(savedLake);
                rains[i] = savedLake;
                continue;
            }

            if(wet.contains(lake)) {
                return {};
            }
            rains[i] = -1;
            if(next[lake].empty()){
                continue;
            }

            wet.insert(lake);
            pq.push(next[lake].front());
            next[lake].pop();
        }

        return rains;
    }
};